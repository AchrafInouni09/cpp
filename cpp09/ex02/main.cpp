#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <sstream>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <sequence of positive integers>" << std::endl;
        return 1;
    }

    std::vector<int> sequence;
    try
    {
        for (int i = 1; i < argc; ++i)
        {
            int num;
            std::istringstream iss(argv[i]);
            if (!(iss >> num) || num < 0)
            {
                throw std::invalid_argument("Error: invalid input");
            }
            sequence.push_back(num);
        }

        PmergeMe sorter;
        sorter.sort(sequence);
    } catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}