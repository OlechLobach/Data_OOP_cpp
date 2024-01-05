#include "date.h"

Date::Date() : day(1), month(1), year(2000) {}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

Date Date::operator++() {
   
    int daysInMonth;
    if (month == 2) {
   
        daysInMonth = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        
        daysInMonth = 30;
    }
    else {
        
        daysInMonth = 31;
    }

  
    if (day >= daysInMonth) {
       
        day = 1;
        month++;

        
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    else {
      
        day++;
    }

    return *this;
}

Date Date::operator--() {
    if (day > 1) {
        day--;
    }
    else {
        if (month == 3 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) {
            day = 29;
        }
        else if (month == 3) {
            day = 28;
        }
        else if (month == 1 || month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11) {
            day = 31;
        }
        else {
            day = 30;
        }
        if (month > 1) {
            month--;
        }
        else {
            month = 12;
            year--;
        }
    }
    return *this;
}

bool Date::operator==(const Date& other) const {
    return day == other.day && month == other.month && year == other.year;
}

bool Date::operator!=(const Date& other) const {
    return !(*this == other);
}

bool Date::operator>(const Date& other) const {
    if (year != other.year) return year > other.year;
    if (month != other.month) return month > other.month;
    return day > other.day;
}

bool Date::operator<(const Date& other) const {
    return !(*this > other || *this == other);
}

Date& Date::operator+=(int daysToAdd) {
    for (int i = 0; i < daysToAdd; ++i) {
        ++(*this);
    }
    return *this;
}

Date& Date::operator-=(int daysToSubtract) {
    for (int i = 0; i < daysToSubtract; ++i) {
        --(*this);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.day << "/" << date.month << "/" << date.year;
    return os;
}

std::istream& operator>>(std::istream& is, Date& date) {
    is >> date.day >> date.month >> date.year;
    return is;
}