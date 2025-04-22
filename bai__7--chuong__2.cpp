#include <iostream>
using namespace std;

class Date {
    int day;
    int month;
    int year;
    int maxDays[12] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
    Date(int _day = 0, int _month = 0, int _year = 0) {
        if (isDateValid(_day, _month, _year)) {
            day = _day;
            month = _month;
            year = _year;
            UpdateFeb();
        }
    }
    int GetDay(){return day;}
    int GetMonth(){return month;}
    int GetYear(){return year;}
    bool isLeap(int _year) {
        return (_year%400==0||(_year%4==0&&_year%100!=0));
    }
    void UpdateFeb() {
        maxDays[1] = isLeap(year)?29:28;
    }
    bool isDateValid(int _day, int _month, int _year) {
        if (_day <= 0 || _day > 31 || _year <= 0 || _month <= 0 || _month > 12)
            return 0;
        if (_month == 2) {
            if (isLeap(_year) && _day <= 29)
                return 1;
            else if (_day <= 28)
                return 1;
            else return 0;
        }
        if (_month == 4 || _month == 6 || _month == 9 || _month == 11)
            return _day <= 30;
        return _day <= 31;
    }
    Date AdvanceDate(int k_day) {
        return *this + k_day;
    }
    friend int DeltaTwoDate(Date param_1, Date param_2) {
        return param_1-param_2;
    }
    friend const Date& MaxDate( Date param_1, Date param_2) {
        return param_1>=param_2?param_1:param_2;
    }
    friend int operator-(Date subtrahendDate, Date minuendDate) {
        Date greaterDate = subtrahendDate>=minuendDate?subtrahendDate:minuendDate;
        Date lessDate = subtrahendDate<=minuendDate?subtrahendDate:minuendDate;
        int deltaDate = 0;
        while (lessDate!=greaterDate) {
            lessDate++;
            deltaDate++;
        }
        return deltaDate;
    }
    friend istream& operator>>(istream& is, Date& param) {
        is >> param.day >> param.month >> param.year;
        if (!param.isDateValid(param.day, param.month, param.year)) {
            param.day = 0;
            param.month = 0;
            param.year = 0;
        }
        param.UpdateFeb();
        return is;
    }
    friend ostream& operator<<(ostream& os, Date param) {
        if (param.isDateValid(param.day, param.month, param.year))
            os << param.day << "/" << param.month << "/" << param.year;
        else
            os << "invalid!";
        return os;
    }
    const int& MaxDayOfMonth() {
        return maxDays[month-1];
    }
    friend Date operator+(Date date, int deltaDays) {
        Date result = date;
        while (deltaDays>0) {
            result.day++;
            if (result.day == result.MaxDayOfMonth() + 1) {
                result.month++;
                result.day = 1;
                if (result.month == 13) {
                    result.month = 1;
                    result.year++;
                    result.UpdateFeb();
                }
            }
            deltaDays--;
        }
        return result;
    }
    friend Date operator-(Date date, int deltaDays) {
        Date result = date;
        while (deltaDays>0) {
            result.day--;
            if (result.day==0) {
                result.month--;
                if (result.month==0) {
                    result.year--;
                    result.month = 12;
                    result.UpdateFeb();
                }
                result.day = result.MaxDayOfMonth();
            }
            deltaDays--;
        }
        return result;
    }
    Date& operator++() {
        *this = *this + 1;
        return *this;
    }
    Date operator++(int) {
        Date curVal = *this;
        (*this) = (*this) + 1;
        return curVal;
    }
    Date& operator--() {
        *this = *this - 1;
        return *this;
    }
    Date operator--(int) {
        Date curVal = *this;
        (*this) = (*this) - 1;
        return curVal;
    }
    friend bool operator>(Date param_1, Date param_2) {
        if (param_1.year==param_2.year) {
            if (param_1.month==param_2.month)
                return param_1.day>param_2.day;
            return param_1.month>param_2.month;
        }
        return param_1.year>param_2.year;
    }
    friend bool operator<(Date param_1, Date param_2) {
        return param_2>param_1;
    }
    friend bool operator==(Date param_1, Date param_2) {
        return param_1.year==param_2.year&&param_1.month==param_2.month&&param_1.day==param_2.day;
    }
    friend bool operator!=(Date param_1, Date param_2) {
        return !(param_1==param_2);
    }
    friend bool operator>=(Date param_1, Date param_2) {
        return param_1>param_2||param_1==param_2;
    }
    friend bool operator<=(Date param_1, Date param_2) {
        return param_2>=param_1;
    }
};

int main() {
    Date sub, min;
    cin >> sub >> min;
    cout << DeltaTwoDate(sub, min) << endl;
    cout << MaxDate(sub, min);
    return 0;
}