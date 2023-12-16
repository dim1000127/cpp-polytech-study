#ifndef DATA_HEADER
#define DATA_HEADER

class Date {
public:
    Date(int, int, int);

    int getYear() const { return year_; }

    int getMonth() const { return month_; }

    int getDay() const { return day_; }

    Date addDays(int days) const;

    static int differenceInDays(const Date &leftDate, const Date &rightDate);

    bool operator==(const Date &date) const;

    bool operator!=(const Date &date) const;

    friend std::ostream &operator<<(std::ostream &stream, const Date &date);

private:
    int getJdn() const;

    int getTotalDays() const;

    static bool isLeapYear(int year);

    constexpr static const int MAX_DAY_IN_MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year_;
    int month_;
    int day_;
};

#endif