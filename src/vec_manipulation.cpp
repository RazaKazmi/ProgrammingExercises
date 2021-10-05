#include "../include/vec_manipulation.h"
#include <iostream>

namespace common_utility
{
    template <typename T>
    std::vector<T> ReverseVec(const std::vector<T>& vec)
    {
        std::vector<T> reversed;
        for(int i = vec.size() - 1; i >= 0; i--) {
            reversed.push_back(vec[i]);
        }
        return reversed;
    }

    // TODO: This is an inefficient method of performing vector
    // reversal which uses unessesary space. 
    // Update this to be more efficient in the future.
    template <typename T>
    void ReverseVector(std::vector<T>& vec)
    {
        //assert vec.empty()
        std::vector<T> temp;
        for(T x: vec)
            temp.push_back(x);
        vec.clear();
        for(int i = temp.size() -1 ; i >= 0; i--)
            vec.push_back(temp[i]);

    }

    void PrintVec(const std::string& label, const std::vector<int>& vec)
    {
        //assert v.empty()
        std::cout << label << ": " << std::endl;
        for(int x : vec)
            std::cout << x << '\n';
    }

    double Maxv(const std::vector<double>& v) 
    {
        //assert v.empty()
        double max_value = v[0];
        for (const double& x : v) {
            if (max_value < x)
                max_value = x;
        }
        return max_value;
    }

    int Maxv(const std::vector<int>& v)
    {
        //assert v.empty()
        double max_value = v[0];
        for (const int& x : v) {
            if (max_value < x)
                max_value = x;
        }
        return max_value;
    }

    double Minv(const std::vector<double>& v)
    {
        //assert v.empty()
        double min_value = v[0];
        for (const int& x : v) {
            if(min_value > x)
                min_value = x;
        }
        return min_value;
    }

    int Minv(const std::vector<int>& v)
    {
        //assert v.empty()
        double min_value = v[0];
        for (const int& x : v) {
            if (min_value > x)
                min_value = x;
        }
        return min_value;
    }
}