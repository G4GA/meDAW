#include <decoded_audio.hpp>

//PCMVal methods

PCMVal::PCMVal(const uint32_t &value) :
    value(value)
{}

PCMVal::PCMVal(const float &value) :
    value(value)
{}

PCMVal::Type PCMVal::getType () const
{
    return static_cast<PCMVal::Type>(this -> value.index());
}

std::optional<float> PCMVal::getFloat () const
{
    return std::holds_alternative<float>(value) ? std::optional<float>(std::get<float>(value)) : std::nullopt;
}

std::optional<uint32_t> PCMVal::getInt () const
{
    return std::holds_alternative<uint32_t>(value) ? std::optional<uint32_t>(std::get<uint32_t>(value)) : std::nullopt;
}

//DecodedAudio methods

DecodedAudio::DecodedAudio(std::shared_ptr<PCMVal[]> pcm_values,
                           const std::size_t &channel_count,
                           const std::size_t &sample_rate,
                           const std::size_t &byte_rate,
                           const std::size_t &bits_per_sample,
                           const std::size_t &block_align) :
    pcm_values      (pcm_values),
    channel_count   (channel_count),
    sample_rate     (sample_rate),
    byte_rate       (byte_rate),
    bits_per_sample (bits_per_sample),
    block_align     (block_align)
{}

DecodedAudio::DecodedAudio(const DecodedAudio &da_object) :
    pcm_values      (da_object.pcm_values),
    channel_count   (da_object.getChannelCount()),
    sample_rate     (da_object.getSampleRate()),
    byte_rate       (da_object.getByteRate()),
    bits_per_sample (da_object.getBitsPerSample()),
    block_align     (da_object.getBlockAlign())
{}

std::size_t DecodedAudio::getChannelCount() const
{
    return channel_count;
}

std::size_t DecodedAudio::getSampleRate() const
{
    return sample_rate;
}

std::size_t DecodedAudio::getByteRate() const
{
    return byte_rate;
}

std::size_t DecodedAudio::getBitsPerSample() const
{
    return bits_per_sample;
}

std::size_t DecodedAudio::getBlockAlign() const
{
    return block_align;
}

PCMVal DecodedAudio::getValueAt(const std::size_t &index) const
{
    return pcm_values[index];
}
