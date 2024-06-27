#include <cstdint>
#include <iostream>
#include <decoded_audio.hpp>
#include <color.hpp>
#include <optional>
#include <ostream>

class UTDecodedAudio 
{
    public:
        UTDecodedAudio();
        void run();
    private:
        const std::uint32_t UINT_VAL = 10;
        const float FLOAT_VAL = 10.5;
        PCMVal *test_pcmval_i;
        PCMVal *test_pcmval_f; 
        void happyPathTest();
};

UTDecodedAudio::UTDecodedAudio() :
    test_pcmval_f(nullptr),
    test_pcmval_i(nullptr)

{}

void UTDecodedAudio::run()
{
        std::cout << tColor::color_o("[decoded_audio.hpp file tests]\n\n", tColor::BOLD);
        std::uint32_t ival = 10;
        float fval = 10.5;
               
        test_pcmval_i = new PCMVal(ival); 
        test_pcmval_f = new PCMVal(fval); 
        
        std::cout << "[Happy path tests]\n";

        happyPathTest();

        delete test_pcmval_f;
        delete test_pcmval_i;
}

void UTDecodedAudio::happyPathTest()
{
    std::cout << tColor::color_o("[PCMVal Methods]\n",
                                 tColor::BOLD);
    std::cout << "UINT Type:\n"; 
    
    std::cout << tColor::printResult(test_pcmval_i->getType() == PCMVal::Type::UINT,
                                     "GetType");
    std::cout << tColor::printResult(test_pcmval_i->getInt().value() == 10,
                                     "getInt");
    std::cout << tColor::printResult(test_pcmval_i->getFloat() == std::nullopt,
                                     "getFloat"); 
    
    std::cout << "FLOAT Type:\n";   
    std::cout << tColor::printResult(test_pcmval_f->getType() == PCMVal::Type::FLOAT,
                                     "GetType");
    std::cout << tColor::printResult(test_pcmval_f->getInt() == std::nullopt, 
                                     "getInt");
    std::cout << tColor::printResult(test_pcmval_f->getFloat().value() == 10.5,
                                     "getFloat");
} 
int main()
{
    UTDecodedAudio u_tester;

    u_tester.run();
    return 0;
}
