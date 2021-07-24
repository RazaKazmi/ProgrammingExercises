#pragma once

#include <iostream>
#include <chrono>

class Timer
{
public:
    Timer(std::string name);
    Timer();
    ~Timer();
private:
    std::string name_;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_, end_;
    std::chrono::duration<float> duration_;
};