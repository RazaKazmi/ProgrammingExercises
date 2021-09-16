#include "variable.h"
#include "../include/common_utilities.h"

double Variable::GetValue(std::string s)
{
    if(var_table.find(s) != var_table.end())
        return var_table[s];
    common_utility::Error("get: undefined variable ", s);
}

void Variable::SetValue(std::string s, double d)
{
    if(var_table.find(s) != var_table.end()) {
        var_table[s] = d;
        return;
    }
    common_utility::Error("set: undefined variable ", s);
}

void Variable::Insert(std::string s, double d)
{
    if(IsDeclared(s))
        common_utility::Error(s," declared twice");
    var_table.insert({s,d});
}

bool Variable::IsDeclared(std::string var)
{
    if(var_table.find(var) != var_table.end())
        return true;
    return false;
}