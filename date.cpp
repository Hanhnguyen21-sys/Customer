//
// Created by Nguyên Nguyễn on 9/15/23.
//
#include "date.h"
#include <iostream>
Date::Date() {
    this->day=1;
    this->month=1;
    this->year=1970;
};
Date::Date(int year, int month, int day) {
    if (month <=0 || month > 12 || day <=0 || day >31)
    {
        cout << "Out of Range";
    }
    this->day=day;
    this->month=month;
    this->year=year;
}
Date::Date(string format) {
    string delimiter="/";
    int pos=format.find(delimiter,0);
    this->month=stoi(format.substr(0,pos));
    format.erase(0,pos+delimiter.length());
    pos= format.find(delimiter);
    this->day= stoi(format.substr(0,pos));
    format.erase(0,pos+delimiter.length());
    this->year= stoi(format);
}
int Date::getYear() const {
    return year;
}
int Date::getMonth() const {
    return month;
}
int Date::getDay() const {
    return day;
}
void Date::setDay(int day){
    this->day=day;
}
void Date::setMonth(int month){
    this->month=month;
}
void Date::setYear(int year){
    this->year=year;
}
string Date::to_String() const {
    return to_string(month) + "/" + to_string(day)+ "/" +to_string(year);
}
void Date::operator=( const Date & rhs)
{
    this->day=rhs.getDay();
    this->month=rhs.getMonth();
    this->year=rhs.getYear();
}
bool Date::operator==(const Date &rhs) const {
    if (this->year== rhs.year && this->month == rhs.getMonth() && this->day==rhs.getDay())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Date::operator!=(const Date &rhs) const {
    if (*this==rhs) {return false;}
    else
    {
        return true;
    }
}

bool Date::operator<(const Date &rhs) const {
    if (this->year > rhs.getYear())
    {
        return false;
    }
    else if (this->year==rhs.getYear() && this->month >rhs.getMonth())
    {
        return false;
    }
    else if (this->year==rhs.getYear() && this->month ==rhs.getMonth() && this->day > rhs.getDay())
    {
        return false;
    }
    return true;
}

bool Date::operator<=(const Date &rhs) const {
    if (*this<rhs || *this==rhs) {return true;}
    else {return false;}
}
bool Date::operator>(const Date &rhs) const {
    return !(*this<=rhs);
}
bool Date::operator>=(const Date &rhs) const {
    if (*this>rhs || *this==rhs) {return true;}
    else {return false;}
}


ostream & operator << (ostream &out, const Date & date)
{
    out << date.getMonth() << "/" << date.getDay() << "/" << date.getYear();
    return out;
}

