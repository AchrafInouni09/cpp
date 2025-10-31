#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <database.csv> <input.txt>" << std::endl;
        return 1;
    }
    try
    {
        BitcoinExchange btc(argv[1], argv[2]);
        btc.processInput();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
