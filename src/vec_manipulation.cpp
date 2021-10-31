#include <iostream>
#include <algorithm>
#include <exception>?

#include "common_utilities.h"
#include "vec_manipulation.h"

namespace common_utility
{
    template <typename T>
    static void CheckVectorEmpty(const std::vector<T>& vec)
    {
        if(vec.empty())
            throw std::out_of_range("Vector argument is empty.");
    }

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
        CheckVectorEmpty(vec);
        std::vector<T> temp;
        for(T x: vec)
            temp.push_back(x);
        vec.clear();
        for(int i = temp.size() -1 ; i >= 0; i--)
            vec.push_back(temp[i]);

    }

    void PrintVec(const std::string& label, const std::vector<int>& vec)
    {
        CheckVectorEmpty(vec);
        std::cout << label << ": " << std::endl;
        for(int x : vec)
            std::cout << x << '\n';
    }

    double Maxv(const std::vector<double>& v) 
    {
        CheckVectorEmpty(v);
        double max_value = v[0];
        for (const double& x : v) {
            if (max_value < x)
                max_value = x;
        }
        return max_value;
    }

    int Maxv(const std::vector<int>& v)
    {
        CheckVectorEmpty(v);
        double max_value = v[0];
        for (const int& x : v) {
            if (max_value < x)
                max_value = x;
        }
        return max_value;
    }

    double Minv(const std::vector<double>& v)
    {
        CheckVectorEmpty(v);
        double min_value = v[0];
        for (const double& x : v) {
            if(min_value > x)
                min_value = x;
        }
        return min_value;
    }

    int Minv(const std::vector<int>& v)
    {
        CheckVectorEmpty(v);
        double min_value = v[0];
        for (const int& x : v) {
            if (min_value > x)
                min_value = x;
        }
        return min_value;
    }

    double MeanVec(const std::vector<int>& v)
    {
        CheckVectorEmpty(v);
        double sum = 0.0;
        for(const int& x : v)
            sum += x;
        double mean = sum / v.size();
        return mean;
    }

    double MeanVec(const std::vector<double>& v)
    {
        CheckVectorEmpty(v);
        double sum = 0.0;
        for(const double& x : v)
            sum += x;
        double mean = sum / v.size();
        return mean;
    }

    double MedianVec(const std::vector<int>& v, bool sorted)
    {
        CheckVectorEmpty(v);
        std::vector<int> sorted_v = v;
        if (sorted = false) {
            std::sort(sorted_v.begin(),sorted_v.end());
        }

        auto middle = sorted_v.size() / 2; 
        //if even
        if(sorted_v.size() % 2 == 0) {
            double median = (sorted_v[middle] + sorted_v[middle-1]) / 2.0;
            return median;
        } else {
            double median = sorted_v[middle];
            return median;
        }
    }

    double MedianVec(const std::vector<double>& v, bool sorted)
    {
        CheckVectorEmpty(v);
        std::vector<double> sorted_v = v;
        if (sorted = false) {
            std::sort(sorted_v.begin(),sorted_v.end());
        }

        auto middle = sorted_v.size() / 2; 
        //if even
        if(sorted_v.size() % 2 == 0) {
            double median = (sorted_v[middle] + sorted_v[middle-1]) / 2.0;
            return median;
        } else {
            double median = sorted_v[middle];
            return median;
        }
    }

    double ModeVec(const std::vector<int>& v)
    {
        return 0;
    }

    double ModeVec(const std::vector<double>& v) 
    {
        return 0;
    }
}