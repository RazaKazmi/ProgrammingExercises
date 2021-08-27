//A simple program that converts temperatures to a different unit.
#include <stdexcept>
#include "../include/common_utilities.h"

static constexpr double kCelsiusToKelvinConstant = 273.15;
static constexpr double kAbsoluteZeroCelsius = -273.15;
static constexpr double kAbsoluteZeroFahrenheit = -459.67;

//convert degrees celsius to Kelvin
double Ctok(double celsius)
//returns temperature in kelvin
//precondition: valid celsius temperature (not below -273.15 degrees celsius)
//post-condition: return a value equal or greater than 0
{
    if(celsius < kAbsoluteZeroCelsius)
        common_utility::Error("Ctok() celsius input is below absolute zero!");
    //k = c + 273.15
    double kelvin = celsius + kCelsiusToKelvinConstant;
    if(kelvin < 0)
        common_utility::Error("Ctok() return value is < 0");
    return kelvin;
}

//convert degrees celsius to degrees fahrenheit
double Ctof(double celsius)
//returns temperature in degrees fahrenheit
//precondition: valid celsius input
//postcondition: return value above absolute zero in fahrenheit
{
    if(celsius < kAbsoluteZeroCelsius)
        common_utility::Error("Ctof() celsius input below absolute zero!");
    //f = c * 9.0/5 + 32
    double fahrenheit = (celsius * 9.0/5.0) + 32.0;
    if(fahrenheit < kAbsoluteZeroFahrenheit)
        common_utility::Error("Ctof() return value < absolute zero");
    return fahrenheit;
}

//convert kelvin to degrees celsius
double Ktoc(double kelvin)
//return temperature in celsius
//precondition: valid kelvin temperature (0 or above)
//postcondition: return value equal or greater than absolute zero
{
    if(kelvin < 0)
        common_utility::Error("Ktoc() kelvin input is invalid (below 0)");
    //c = k - 273.15
    double celsius = kelvin - kCelsiusToKelvinConstant;
    if(celsius < kAbsoluteZeroCelsius)
        common_utility::Error("Ktoc() return value is < absolute zero");
    return celsius;
}

//convert kelvin to degrees fahrenheit
double Ktof(double kelvin)
{
    if(kelvin < 0)
        common_utility::Error("Ktof() kelvin input is invalid (below 0)");
    //f = (k - 273.15) * 9.0/5.0 + 32
    double fahrenheit = (kelvin - kCelsiusToKelvinConstant) * 9.0/5.0 + 32;
    if(fahrenheit < kAbsoluteZeroFahrenheit)
        common_utility::Error("Ktof() return value is < absolute zero");
    return fahrenheit;
}

//convert degrees fahrenheit to celcius
double Ftoc(double fahrenheit)
{
    if(fahrenheit < kAbsoluteZeroFahrenheit)
        common_utility::Error("Ftoc() fahrenheit input < absolute zero");
    //c = (f - 32) * 5.0/9.0
    double celsius = (fahrenheit - 32.0) * 5.0/9.0;
    if(celsius < kAbsoluteZeroCelsius)
        common_utility::Error("Ftoc celcius return value is < absolute zero");
    return celsius;
}

//convert degrees fahrenheit to kelvin
double Ftok(double fahrenheit)
{
    if(fahrenheit < kAbsoluteZeroFahrenheit)
        common_utility::Error("Ftok fahrenheit input < absolute zero");
    //k = (f-32) * 5.0/9.0 + 273.15
    double kelvin = (fahrenheit - 32.0) * 5.0/9.0 + 273.15;
    if(kelvin < 0)
        common_utility::Error("Ftok kelvin return value is < absolute zero");
    return kelvin;
}

static void PrintInstructions()
{
    common_utility::Print("Please enter the value and unit of the temperature you want converted. Example, 15C: ");
}

static void TemperatureConversionProgram()
{
    double temperature = 0;
    char unit = ' ';
    std::cin >> temperature >> unit;

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