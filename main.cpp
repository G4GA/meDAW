#include <iostream>
#include <decoded_audio.hpp>

int main ()
{
    float n = 3.5;
    PCMVal foo(n);
    PCMVal::Type fooVal = foo.getType();

    std::cout << "Variant type: " << static_cast<std::underlying_type<PCMVal::Type>::type>(fooVal);

    return 0;
}