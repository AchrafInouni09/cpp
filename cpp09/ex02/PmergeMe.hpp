#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>
#include <stdexcept>

class PmergeMe 
{
public:

    PmergeMe();

   
    void sort(const std::vector<int> &sequence);

private:

    void mergeInsertSort(std::vector<int> &vec);
    void mergeInsertSort(std::list<int> &lst);
};

#endif