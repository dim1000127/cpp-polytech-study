#include <iostream>
#include "date.h"

int main() {

    try {
        Date date1(27, 0, 2012);

        std::cout << "Date1 - " << date1 << std::endl;

        std::cout << "Year: " << date1.getYear()
                  << " Month: " << date1.getMonth()
                  << " Day: " << date1.getDay() << std::endl;

        Date date2(27, 2, 2014);
        Date date3(15, 2, 2024);

        std::cout << std::endl;
        std::cout << "Date comparison" << std::endl;
        std::cout << "Date1 = Date2? - " << (date1 == date2) << std::endl;
        std::cout << "Date1 = Date3? - " << (date1 == date3) << std::endl;
        std::cout << "Date1 != Date2? - " << (date1 != date2) << std::endl;

        std::cout << std::endl;
        std::cout << "Date3 - " << date3 << std::endl;
        int foo = -2400000;
        Date newDate = date3.addDays(foo);
        std::cout << "Date3 after + " << foo << " - " << newDate << std::endl;

        std::cout << std::endl;
        Date date4 = Date(27, 2, 2013);
        Date date5 = Date(27, 2, -2013);
        std::cout << "Date4 - " << date4 << std::endl;
        std::cout << "Date5 - " << date5 << std::endl;
        std::cout << "Difference btw date4 and date5 - " << (Date::differenceInDays(date4, date5)) << std::endl;

        std::cout << std::endl;
        Date date6 = Date(27, 2, -2013);
        Date date7 = Date(27, 2, 2013);
        std::cout << "Date6 - " << date6 << std::endl;
        std::cout << "Date7 - " << date7 << std::endl;
        std::cout << "Difference btw date6 and date7 - " << (Date::differenceInDays(date6, date7)) << std::endl;

        std::cout << std::endl;
        Date date8 = Date(27, 2, 2013);
        Date date9 = Date(27, 3, 2016);
        std::cout << "Date8 - " << date8 << std::endl;
        std::cout << "Date9 - " << date9 << std::endl;
        std::cout << "Difference btw date8 and date9 - " << (Date::differenceInDays(date8, date9)) << std::endl;
    }
    catch (const std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
