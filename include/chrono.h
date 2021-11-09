#pragma once

#include <iostream>

namespace Chrono 
{

    enum class Month 
    {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    class Date 
    {
        public:
            class Invalid{};
            // Check for valid date and initalize
            Date(int y, Month m, int d);
            Date();

            //Non modifying  operations
            int GetDay() const {return _day;};
            Month GetMonth() const {return _month;}
            int GetYear() const {return _year;}

            // Modifying operations
            void AddDay(int n);
            void AddMonth(int n);
            void AddYear(int n);

        private:
            int _year;
            Month _month;
            int _day;
    };

    const Date& DefaultDate();

    // True for valid date
    bool IsDate(int y, Month m, int d);
    // True if y is a leap year
    bool LeapYear(int y);

    bool operator==(const Date& a, const Date&b);
    bool operator!=(const Date& a, const Date& b);

    std::ostream& operator<<(std::ostream& os, const Date& d);
    std::istream& operator>>(std::istream& is, Date& dd);

}