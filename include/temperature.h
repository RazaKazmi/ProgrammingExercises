#pragma once

namespace temperature
{
    //convert degrees celsius to Kelvin
    double Ctok(double celsius);
    //convert degrees celsius to degrees fahrenheit
    double Ctof(double celsius);
    //convert kelvin to degrees celsius
    double Ktoc(double kelvin);
    //convert kelvin to degrees fahrenheit
    double Ktof(double kelvin);
    //convert degrees fahrenheit to celsius
    double Ftoc(double fahrenheit);
    //convert degrees fahrenheit to kelvin
    double Ftok(double fahrenheit);
}