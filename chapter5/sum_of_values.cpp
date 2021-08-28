//This program reads a series of values and then computes the sum of the first N values.
//User input is what decides what N is.
#include "../include/common_utilities.h"
#include <vector>
#include <exception>

static void PrintInstructions()
{
    std::cout << "This program computes the sum of values in order sequentially." << '\n'
    << "Please enter how many values you want the sum of: ";
}
static void ReadValues(std::vector<double>& values)
{
    double value;
    while(std::cin >> value){
        if(!std::cin)
            common_utility::Error("Invalid input reading values!");
        values.push_back(value);
    }
}
double ComputeSum(std::vector<double>& values, int n)
{
    if(n > values.size())
        throw std::out_of_range("ComputeSum() is trying to compute more values then in the list of values.");
    double sum = 0;
    for(int i = 0; i<n;i++){
        sum += values[i];
    }
    return sum;
}

int main()
{
    try{
        PrintInstructions();
        int n = 0;
        std::cin >> n;
        if(!std::cin)
            common_utility::Error("Invalid input for n. Expecting an integer");
        std::cout << "Please enter your sequence of values (press 'ctrl + z' to stop):" << '\n';
        //Read values in to a vector
        std::vector<double> values;
        ReadValues(values);
        std::cout << "The sum is: " << ComputeSum(values, n) << std::endl;
    }
    catch(std::exception& e){
        std::cerr << "error: " << e.what() << '\n';
        common_utility::KeepWindowOpen();
        return 1;
    }
    catch(...){
        std::cerr << "Unknown exception!\n";
        common_utility::KeepWindowOpen();
        return 2;
    }



}