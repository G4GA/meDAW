#pragma once

#include <variant>
#include <cstdint>
#include <optional>
#include <memory>


class PCMVal
{
    private:
        std::variant<std::uint32_t, float> value;
    public:
        PCMVal(const std::uint32_t &);
        PCMVal(const float &);
        
        enum class Type
        {
            UINT,
            FLOAT
        };
        
        Type getType() const;
        std::optional<std::uint32_t> getInt() const;
        std::optional<float> getFloat() const;     
};

class DecodedAudio
{
    private:
        std::shared_ptr<PCMVal[]> pcm_values;
        // Metadata
        std::size_t channel_count;
        std::size_t sample_rate;
        std::size_t byte_rate;
        std::size_t bits_per_sample;
        std::size_t block_align;
    public:
        DecodedAudio(std::shared_ptr<PCMVal[]>,
                     const std::size_t &,
                     const std::size_t &,
                     const std::size_t &,
                     const std::size_t &,
                     const std::size_t &);

        DecodedAudio(const DecodedAudio &);
        //Getters ad setters
        std::size_t getChannelCount() const;
        std::size_t getSampleRate() const;
        std::size_t getByteRate() const;
        std::size_t getBitsPerSample() const;
        std::size_t getBlockAlign() const;

        PCMVal getValueAt(const std::size_t &) const;
};

