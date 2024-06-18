#pragma once

#include <vector>
#include <variant>
#include <cstdint>
#include <optional>
#include <memory>

class PCMVal
{
    private:
        std::variant<uint32_t, float> value;
    public:
        PCMVal(const uint32_t &);
        PCMVal(const float &);
        enum class Type
        {
            UINT,
            FLOAT
        };
        Type getType();
        std::optional<int> getInt();
        std::optional<float> getFloat();
};

class DecodedAudio
{
    private:
        std::unique_ptr<PCMVal[]> pcm_values;
        // Metadata
        std::size_t channel_count;
        std::size_t sample_rate;
        std::size_t byte_rate;
        std::size_t bits_per_sample;
        std::size_t block_align;
    public:
        DecodedAudio(std::unique_ptr<PCMVal[]>,
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