#include <cmath>
#include <iostream>
#include <stdexcept>
#include "date.h"

Date::Date(int day, int month, int year) {
    if (year == 0)
        throw std::invalid_argument("Year can't be 0");

    year_ = year;
    if (month > 12 || month == 0)
        throw std::invalid_argument("Month can't be 0 or more than 12");

    month_ = month;

    if (day == 0)
        throw std::invalid_argument("Day can't be 0");

    if (month == 2) {
        if (isLeapYear(year) && day > 29) {
            throw std::invalid_argument("Can't be more than 29 days in February");
        }

        if (!isLeapYear(year) && day > 28) {
            throw std::invalid_argument("Can't be more than 28 days in February");
        }
    }

    if ((month == 9 || month == 11 || month == 6 || month == 4) && day > 30)
        throw std::invalid_argument("Can't be more than 30 days in September, November, April, June");

    if ((month == 1 || month == 3 || month == 5 || month == 7 ||
         month == 8 || month == 10 || month == 12) && day > 31)
        throw std::invalid_argument("Can't be more than 31 days in January, March, May, July, August, October, December");

    day_ = day;
}

int Date::differenceInDays(const Date &leftDate, const Date &rightDate) {
    int leftTotalDays = leftDate.getTotalDays();
    int rightTotalDays = rightDate.getTotalDays();

    if (leftDate.year_ < 0 && rightDate.year_ > 0) leftTotalDays *= -1;
    if (rightDate.year_ < 0 && leftDate.year_ > 0) rightTotalDays *= -1;

    return abs(leftTotalDays - rightTotalDays);
    //return abs(leftDate.getJdn() - rightDate.getJdn());
}

Date Date::addDays(int daysBeingAdded) const {
    int d = day_ + daysBeingAdded;
    int m = month_;
    int y = year_;
    int maxDaysInMonth = MAX_DAY_IN_MONTH[m - 1] + (m == 2 && isLeapYear(y) ? 1 : 0);

    if (daysBeingAdded > -1) {
        while (d > maxDaysInMonth) {
            d -= maxDaysInMonth;
            if (++m > 12) {
                m = 1;
                ++y;
                if (y == 0) ++y;
            }
            maxDaysInMonth = MAX_DAY_IN_MONTH[m - 1] + (m == 2 && isLeapYear(y) ? 1 : 0);
        }
    } else {
        while (d <= 0) {
            if (--m == 0) {
                m = 12;
                --y;
                if (y == 0) --y;
            }
            maxDaysInMonth = MAX_DAY_IN_MONTH[m - 1] + (m == 2 && isLeapYear(y) ? 1 : 0);
            d += maxDaysInMonth;
        }
    }

    return {d, m, y};

    //JDN

    /*int jdn = getJdn();
    jdn += daysBeingAdded;

    //Gregorian calendar from Julian day number
    int f = jdn + 1401 + (((4 * jdn + 274277) / 146097) * 3) / 4 + (-38);
    int e = 4 * f + 3;
    int g = (e % 1461) / 4;
    int h = 5 * g + 2;
    int day = (h % 153) / 5 + 1;
    int month = (h / 153 + 2) % 12 + 1;
    int year = e / 1461 - 4716 + (12 + 2 - month_) / 12;
    return {day, month, year};*/
}

bool Date::operator==(const Date &date) const {
    return year_ == date.year_ &&
           month_ == date.month_ &&
           day_ == date.day_;
}

bool Date::operator!=(const Date &date) const {
    return !(*this == date);
}

std::ostream &operator<<(std::ostream &stream, const Date &date) {
    return stream << date.day_ << "."
                  << date.month_ << "."
                  << date.year_;
}

bool Date::isLeapYear(int year) {
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

int Date::getJdn() const {
    int a = (14 - month_) / 12;
    int y = year_ + 4800 - a;
    int m = month_ + 12 * a - 3;

    return day_ + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
}

int Date::getTotalDays() const {
    int totalDays = (abs(year_) * 365);
    totalDays -= 365;

    int year = abs(year_);

    if (month_ <= 2) --year;

    int leapYearDays = ((year / 4) + (year / 400) - (year / 100));
    totalDays += leapYearDays;

    if (year_ > 0) {
        for (int i = 0; i < (month_ - 1); i++)
            totalDays += MAX_DAY_IN_MONTH[i];

        totalDays += day_;
    } else {
        for (int i = 12; i > (month_ - 1); i--)
            totalDays += MAX_DAY_IN_MONTH[i];
        totalDays += MAX_DAY_IN_MONTH[month_ - 1] - day_;
    }
    return totalDays;
}