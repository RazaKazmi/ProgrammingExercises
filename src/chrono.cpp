#include "../include/chrono.h"

namespace Chrono
{
    Date::Date(int yy, Month mm, int dd)
        :_year{yy}, _month{mm}, _day{dd}
    {
        if(!IsDate(yy,mm,dd))
            throw Invalid{};
    }

    const Date& DefaultDate()
    {
        static Date dd{2021,Month::jan,1};
        return dd;
    }

    Date::Date()
        :_year{DefaultDate().GetYear()},
        _month{DefaultDate().GetMonth()},
        _day{DefaultDate().GetDay()}
        {
        }

    void Date::AddDay(int n)
    {

    }

    void Date::AddMonth(int n)
    {

    }

    void Date::AddYear(int n)
    {

    }

    // Helper Functions
    
    bool IsDate(int y, Month m, int d)
    {
        // Assume y is a valid year
        if( d<=0) // less then 0 days
            return false;
        if(m < Month::jan || Month::dec < m)
            return false;

        int days_in_month = 31;

        switch(m) {
            case Month::feb:
                days_in_month = (LeapYear(y)) ? 29 : 28; // Febs days depend on leap year
                break;
            case Month::apr:
			case Month::jun:
			case Month::sep:
			case Month::nov:
				days_in_month = 30;	
				break;
        }

        if (days_in_month < d) // Inputted day is greater then the month has
            return false;
        
        return true;
    }

    bool LeapYear(int y)
    {
        // If year is divisible by 4 evenly, it's a leap year
        if( y % 4 == 0) {
            return true;
        } else
        {
            return false;
        }
    }

    bool operator==(const Date& a, const Date& b)
    {
        return a.GetYear() == b.GetYear()
        && a.GetMonth() == b.GetMonth()
        && a.GetDay() == a.GetDay();
    }

    bool operator!=(const Date& a, const Date& b)
    {
        return !(a == b);
    }

    /*
    std::ostream& operator<<(std::ostream& os, const Date& d)
    {
        return os << '(' << d.GetYear() << ',' << d.GetMonth() << ',' << d.GetDay() << ')';
    }
    */

   std::istream& operator>>(std::istream& is, Date& dd)
   {
       int y, m, d;
       char ch1, ch2, ch3, ch4;
       is >> ch1, y >> ch2 >> m >> ch3 >> d >> ch4;
        if(!is)
            return is;
    
        // Format error
        if(ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')
        {
            is.clear(std::ios_base::failbit);
            return is;
        }
   }

}