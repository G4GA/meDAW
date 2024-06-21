#include <cstdint>
#include <iostream>
#include <decoded_audio.hpp>
#include <color.hpp>

class UTDecodedAudio 
{
    public:
        void run();
    private:
};

void UTDecodedAudio::run()
{
        std::cout << tColor::color_o("[DecodedAudio class tests]\n", tColor::BOLD);
        uint32_t val = 10;
        float fval = 10.5;
        PCMVal test_pcmval_i(val);
        PCMVal test_pcmval_f(fval);

        std::cout << tColor::printResult(true, "Test");
}

int main()
{
    UTDecodedAudio u_tester;

    u_tester.run();
    return 0;
}
