#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <ctime>

PmergeMe::PmergeMe() {}

void PmergeMe::sort(const std::vector<int> &sequence)
{
    std::vector<int> vec(sequence);
    std::list<int> lst(sequence.begin(), sequence.end());

    std::clock_t startVec = std::clock();
    mergeInsertSort(vec);
    std::clock_t endVec = std::clock();
    double vecTime = (double)(endVec - startVec) / (double)CLOCKS_PER_SEC * 1e6;

    std::clock_t startLst = std::clock();
    mergeInsertSort(lst);
    std::clock_t endLst = std::clock();
    double lstTime = (double)(endLst - startLst) / (double)CLOCKS_PER_SEC * 1e6;

    std::cout << "Before: ";
    for (std::vector<int>::size_type i = 0; i < sequence.size(); ++i)
    {
        std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "After: ";
    for (std::vector<int>::size_type i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << sequence.size() << " elements with std::vector: " << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << sequence.size() << " elements with std::list: " << lstTime << " us" << std::endl;
}

void PmergeMe::mergeInsertSort(std::vector<int> &vec)
{
    if (vec.size() <= 1)
        return;

    std::vector<int>::iterator mid = vec.begin() + vec.size() / 2;
    std::vector<int> left(vec.begin(), mid);
    std::vector<int> right(mid, vec.end());

    mergeInsertSort(left);
    mergeInsertSort(right);

    std::merge(left.begin(), left.end(), right.begin(), right.end(), vec.begin());
}

void PmergeMe::mergeInsertSort(std::list<int> &lst)
{
    if (lst.size() <= 1)
        return;

    std::list<int>::iterator mid = lst.begin();
    std::advance(mid, lst.size() / 2);
    std::list<int> left(lst.begin(), mid);
    std::list<int> right(mid, lst.end());

    mergeInsertSort(left);
    mergeInsertSort(right);

    lst.merge(left);
    lst.merge(right);
}