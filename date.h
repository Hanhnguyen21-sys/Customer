//
// Created by Nguyên Nguyễn on 9/15/23.
//
#include<string>
#ifndef LAB1_CUSTOMER_DATE_H
#define LAB1_CUSTOMER_DATE_H
using namespace std;
class Date {
private:
    int day;
    int month;
    int year;
public:
    Date();
    Date (int year,int month,int day);
    Date (string format);
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    string to_String() const;
    bool operator==(const Date &rhs) const;
    bool operator!=(const Date &rhs) const;
    bool operator<(const Date &rhs) const;
    bool operator<=(const Date &rhs) const;
    bool operator>=(const Date &rhs) const;
    bool operator>(const Date &rhs) const;
    void operator=(const Date&rhs);
};
ostream & operator << (ostream &out, const Date & date);
#endif //LAB1_CUSTOMER_DATE_H
