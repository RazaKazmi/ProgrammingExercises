//A simple program that converts temperatures to a different unit.
#include <stdexcept>
#include "../include/common_utilities.h"
#include "../include/temperature.h"


static void PrintInstructions()
{
    common_utility::Print("Please enter the value and unit of the temperature you want converted. Example, 15C: ");
}

static void TemperatureConversionProgram()
{
    using namespace temperature;
    double temperature = 0;
    char unit = ' ';
    std::cin >> temperature >> unit;
    if(!std::cin)
        common_utility::Error("temperature input is invalid!");

    std::cout << temperature << unit << " Converted: \n";
    switch(unit){
        case 'c': case 'C':
            //celsius to kelvin
            std::cout << Ctok(temperature) << "K\n";
            //celsius to fahrenheit
            std::cout << Ctof(temperature) << "F\n";
            break;
        case 'f': case 'F':
            //fahrenheit to kelvin
            std::cout << Ftok(temperature) << "K\n";
            //fahrenheit to celsius
            std::cout << Ftoc(temperature) << "C\n";
            break;
        case 'k': case 'K':
            //kelvin to celsius
            std::cout << Ktoc(temperature) << "C\n";
            //kelvin to fahrenheit
            std::cout << Ktof(temperature) << "F\n";
            break;

    }
}

int main()
{
    try{
        PrintInstructions();
        TemperatureConversionProgram();
        common_utility::KeepWindowOpen();
        return 0;
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