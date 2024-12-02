// CombinationSub2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

bool operator ==(const std::vector<int>& v1, const std::vector<int>& v2)
{
    if (v1.size() != v2.size())
        return false;

    for (auto n1 : v1)
    {
        bool found = false;
        for (auto n2 : v2)
        {
            if (n1 == n2)
            {
                found = true;
                break;
            }
        }

        if (!found)
            return false;
    }

    return true;
}

bool Find(const std::vector<std::vector<int>>& vv, const std::vector<int>& v)
{
    if (vv.empty())
        return false;

    for (auto& vec : vv)
    {
        if (v == vec)
            return true;
    }

    return false;
}

void FindCombination(const std::vector<int>& vec, int sum, size_t index, std::vector<int>& r, std::vector<std::vector<int>>& result)
{
    if (sum == 0)
    {
        if (!Find(result, r))
            result.push_back(r);
        if (index == vec.size())
            return;
    }

    // if the array vec is sorted, here we should add condition to check if the
    //  current element is greater than the sum. if so, it can return
    if (index == vec.size() /*|| vec[index] > sum*/)
        return;

    for (size_t i = index; i < vec.size(); ++i)
    {
        r.push_back(vec[i]);
        FindCombination(vec, sum - vec[i], i + 1, r, result);
        r.pop_back();
    }
}

std::vector<std::vector<int>> CombinationSum(std::vector<int>& A, int val)
{
    // to use the default operator == of vectors, we need to sort A
    //  in this example, I wrote my own operator == for vectors, so
    //  sorting vector A is not needed
    std::vector<std::vector<int>> result;
    std::vector<int> r;

    for (size_t i = 0; i < A.size(); ++i)
        FindCombination(A, val, i, r, result);

    return result;
}

int main()
{
    while (true)
    {
        std::cout << "Number of elements in array: ";
        int count = 0;
        std::cin >> count;
        if (count == 0)
            break;

        std::cout << "Numbers in array: ";
        std::vector<int> vec(count, 0);
        for (int i = 0; i < count; ++i)
            std::cin >> vec[i];

        std::cout << "The sum: ";
        int sum;
        std::cin >> sum;

        std::vector<std::vector<int>> r = CombinationSum(vec, sum);
        for (auto& vv : r)
        {
            if (!vv.empty())
                std::cout << vv[0];
            for (auto i = vv.begin() + 1; i != vv.end(); ++i)
                std::cout << ", " << *i;
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}
