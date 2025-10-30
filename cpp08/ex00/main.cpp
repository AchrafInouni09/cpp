#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {
    try {
        std::vector<int> vec;

        for (int i = 1; i <= 5; ++i) {
            vec.push_back(i);
        }
        std::cout << "Found: " << easyfind(vec, 3) << std::endl;
        std::cout << "Found: " << easyfind(vec, 6) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::list<int> lst ;
        for (int i = 10; i <= 20; ++i)
        {
            lst.push_back(i);
        }
        std::cout << "Found: " << easyfind(lst, 20) << std::endl;
        std::cout << "Found: " << easyfind(lst, 60) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}