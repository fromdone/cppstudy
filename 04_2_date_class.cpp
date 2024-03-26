#include <iostream>

class Date {
    int year;
    int month;
    int day;

    public:
    void SetDate(int _year, int _month, int _day);
    void AddYear(int inc);
    void AddMonth(int inc);
    void AddDay(int inc);

    int GetCurrentMonthTotalDays(int _year, int _month);

    void ShowDate();

    Date(int _year, int _month, int _day) { //constructor
        year = _year;
        month = _month;
        day = _day;
    }

    Date() {
        year = 1990;
        month = 10;
        day = 17;
    }
};

void Date::SetDate(int _year, int _month, int _day) {
    year = _year;
    month = _month;
    day = _day;
}

int Date::GetCurrentMonthTotalDays(int _year, int _month) {
    static int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month != 2) {
        return month_days[_month-1];
    } else if (_year%4 == 0 && _year%100 == 0 && _year%400 != 0) { //?œ¤?…„
        return 29;
    } else {
        return 28;
    }
}

void Date::AddYear(int inc) {
    year += inc;
}

void Date::AddMonth(int inc) {
    AddYear((month+inc-1)/12);
    month = (month+inc)%12;
    if (month == 0) {
        month = 12;
    }
}

void Date::AddDay(int inc) {
    while (true) {
        int this_month_days = GetCurrentMonthTotalDays(year, month);

        if (day+inc <= this_month_days) {
            day = day + inc;
            return;
        } else {
            inc = inc + 1 - (this_month_days-day);
            AddMonth(1);
            day = 1;
        }
    }
}

void Date::ShowDate() {
    std::cout << "?˜¤?Š˜??? " << year << "?…„ " << month << "?›” " << day << "?¼ ?ž…?‹ˆ?‹¤." << std::endl;
}

int main() {
    Date day(2024, 3, 8);
    Date day2;
    day.ShowDate();
    day2.ShowDate();

    day.AddYear(10);
    day2.AddYear(10);
    day.ShowDate();
    day2.ShowDate();



    return 0;
}