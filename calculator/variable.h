#pragma once

#include <iostream>
#include <unordered_map>

class Variable 
{
public:
    Variable() {}
    double GetValue(std::string s);
    void SetValue(std::string s, double d);
    void Insert(std::string s, double d);

    bool IsDeclared(std::string var); // is var alread in var_table

private:
    std::unordered_map<std::string,double> var_table;
};