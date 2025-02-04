#include "Harl.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "error" << std::endl;
        return 1;
    }
    // std::cout <<  argv[1] << std::endl;
    Harl harl(argv[1]);
    harl.complain();
    return 0;
}