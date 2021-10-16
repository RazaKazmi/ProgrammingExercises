#pragma once

#include <vector>
#include <string>

namespace common_utility
{
    // Reversal
    template <typename T>
    std::vector<T> ReverseVec(const std::vector<T>& vec);
    template <typename T>
    void ReverseVector(std::vector<T>& vec);

    // Printing
    void PrintVec(const std::string& label, const std::vector<int>& vec);

    // Min and Max for unsorted vectors
    double Maxv(const std::vector<double>& v);                                                                                                                                                                                                                                                                                                             
    int Maxv(const std::vector<int>& v);
    double Minv(const std::vector<double>& v);
    int Minv(const std::vector<int>& v);
    
    // Mean, median, and mode for vectors
    double MeanVec(const std::vector<int>& v);
    double MeanVec(const std::vector<double>& v);
    double MedianVec(const std::vector<int>& v, bool sorted);
    double MedianVec(const std::vector<double>& v, bool sorted);
    double ModeVec(const std::vector<int>& v);
    double ModeVec(const std::vector<double>& v);

}