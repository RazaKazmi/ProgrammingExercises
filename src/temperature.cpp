#include "../include/temperature.h"
#include "../include/common_utilities.h"

static constexpr double kCelsiusToKelvinConstant = 273.15;
static constexpr double kAbsoluteZeroCelsius = -273.15;
static constexpr double kAbsoluteZeroFahrenheit = -459.67;

namespace temperature
{
    double Ctok(double celsius)
    //returns temperature in kelvin
    //precondition: valid celsius temperature (not below -273.15 degrees celsius)
    //post-condition: return a value equal or greater than 0
    {
        if (celsius < kAbsoluteZeroCelsius)
            common_utility::Error("Ctok() celsius input is below absolute zero!");
        //k = c + 273.15
        double kelvin = celsius + kCelsiusToKelvinConstant;
        if (kelvin < 0)
            common_utility::Error("Ctok() return value is < 0");
        return kelvin;
    }
    double Ctof(double celsius)
    //returns temperature in degrees fahrenheit
    //precondition: valid celsius input
    //postcondition: return value above absolute zero in fahrenheit
    {
        if (celsius < kAbsoluteZeroCelsius)
            common_utility::Error("Ctof() celsius input below absolute zero!");
        //f = c * 9.0/5 + 32
        double fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
        if (fahrenheit < kAbsoluteZeroFahrenheit)
            common_utility::Error("Ctof() return value < absolute zero");
        return fahrenheit;
    }
    double Ktoc(double kelvin)
    //return temperature in celsius
    //precondition: valid kelvin temperature (0 or above)
    //postcondition: return value equal or greater than absolute zero
    {
        if (kelvin < 0)
            common_utility::Error("Ktoc() kelvin input is invalid (below 0)");
        //c = k - 273.15
        double celsius = kelvin - kCelsiusToKelvinConstant;
        if (celsius < kAbsoluteZeroCelsius)
            common_utility::Error("Ktoc() return value is < absolute zero");
        return celsius;
    }
    double Ktof(double kelvin)
    //return temperature in fahrenheit
    //precondition: valid kelvin temperature
    //postcondition: return fahrenheit equal or greater than absolute zero
    {
        if (kelvin < 0)
            common_utility::Error("Ktof() kelvin input is invalid (below 0)");
        //f = (k - 273.15) * 9.0/5.0 + 32
        double fahrenheit = (kelvin - kCelsiusToKelvinConstant) * 9.0 / 5.0 + 32;
        if (fahrenheit < kAbsoluteZeroFahrenheit)
            common_utility::Error("Ktof() return value is < absolute zero");
        return fahrenheit;
    }
    double Ftoc(double fahrenheit)
    //return temperature in degrees celsius
    //precondition: valid fahrenheit temperature
    //postcondition: return celsius equal or greater than absolute zero
    {
        if (fahrenheit < kAbsoluteZeroFahrenheit)
            common_utility::Error("Ftoc() fahrenheit input < absolute zero");
        //c = (f - 32) * 5.0/9.0
        double celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
        if (celsius < kAbsoluteZeroCelsius)
            common_utility::Error("Ftoc celcius return value is < absolute zero");
        return celsius;
    }
    double Ftok(double fahrenheit)
    //return temperature in kelvin
    //precondition: valid fahrenheit temperature
    //postconditions: return kelvin equal or greater than 0 (absolute zero)
    {
        if (fahrenheit < kAbsoluteZeroFahrenheit)
            common_utility::Error("Ftok fahrenheit input < absolute zero");
        //k = (f-32) * 5.0/9.0 + 273.15
        double kelvin = (fahrenheit - 32.0) * 5.0 / 9.0 + 273.15;
        if (kelvin < 0)
            common_utility::Error("Ftok kelvin return value is < absolute zero");
        return kelvin;
    }

}