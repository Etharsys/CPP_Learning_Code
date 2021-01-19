#include <iostream>
#include <string>
#include <tuple>


std::tuple<bool, int, int> parse_params(int argc, const char* const* argv)
{
    const std::tuple<bool, int, int> error { false, 0, 0 };
    if (argc != 3)
    {
        std::cerr << "Program expects 2 parameters!" << std::endl;
        return error;
    }

    std::string num_str = argv[1];
    std::string den_str = argv[2];
    int numerator = 0;
    int denominator = 0;
    
    try
    {
        numerator = std::stoi(num_str);
        denominator = std::stoi(den_str);
    }
    catch (const std::exception&)
    {
        std::cerr << "Program expects 2 integer parameters!" << std::endl;
        return error;
    }
    
    if (denominator == 0)
    {
        std::cerr << "Denominator cannot be null!" << std::endl;
        return error;
    }

    return std::tuple<bool, int, int> { true, numerator, denominator };
}

std::tuple<int, int> divide (int num, int den)
{
    return std::tuple { num / den, num % den };
}


int main(int argc, char** argv)
{
    const auto parse_res = parse_params(argc, argv);
    if (!std::get<0>(parse_res))
    {
        return 1;
    }

    const auto numerator = std::get<1>(parse_res);
    const auto denominator = std::get<2>(parse_res);
    const auto quotient = divide(numerator, denominator);

    std::cout << numerator << " = " << denominator << " * " << std::get<0>(quotient) << " + " << std::get<1>(quotient) << std::endl;   

    return 0;
}