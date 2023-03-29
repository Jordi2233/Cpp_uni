#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    double sum = 0.0;

    if (argc == 1 || std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h")
    {
        std::cout << "Użycie: Program służy do sumowania podanych argumentów" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; ++i)
    {
        sum += std::stod(argv[i]);
    }

    std::cout << "Suma argumentów: " << sum << std::endl;
    return 0;
}
