#include "../include/decoded_audio.hpp"
#include <optional>
#include <variant>

//Define PCMVal methods

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

std::optional<int> PCMVal::getInt () const
{
    return std::holds_alternative<int>(value) ? std::optional<int>(std::get<int>(value)) : std::nullopt;
}


