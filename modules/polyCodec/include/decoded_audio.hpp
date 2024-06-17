#pragma once

#include <memory>

class DecodedAudio
{
    public:
    private:
        union _PCMValue
        {
            long i_pcm_val;
            float f_pcm_val;
        };
    private:
        // PCM audio data
        std::shared_ptr<_PCMValue[]> PCM_values;
        // Metadata
        size_t channel_count;
        size_t sample_rate;
        size_t byte_rate;
        size_t bits_per_sample;
        size_t block_align;
};