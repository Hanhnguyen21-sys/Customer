//
// Created by Nguyên Nguyễn on 9/15/23.
//
#include "customer.h"
#include "date.h"
#include <sstream>
using namespace std;
CustomerCompareOptions Customer::option;
Customer::Customer() {
    this->customer_id="";
    this->username="";
    this->first_name="";
    this->last_name="";
    this->street_address="";
    this->city="";
    this->state="";
    this->postal_code="";
    this->email_address="";
    this->gender="";
    this->company="";
    this->job_title="";
    this->customer_since = Date();
    this->social_security_number="";
    this->date_of_birth=Date();
    this->household_income=0;
    this->credit_score=0;
    this->total_sales=0;
}
Customer::Customer(string customer_id, string username, string first_name, string last_name, string street_address,
                   string city, string state, string postal_code, string email_address, string gender, string company, string job_title,
                   Date customer_since, string social_security_number, Date date_of_birth, int household_income,
                   int credit_score, double total_sales) {
    this->customer_id=customer_id;
    this->username=username;
    this->first_name=first_name;
    this->last_name=last_name;
    this->street_address=street_address;
    this->city=city;
    this->state=state;
    this->postal_code=postal_code;
    this->email_address=email_address;
    this->gender=gender;
    this->company=company;
    this->job_title=job_title;
    this->customer_since=customer_since;
    this->social_security_number=social_security_number;
    this->date_of_birth=date_of_birth;
    this->household_income=household_income;
    this->credit_score=credit_score;
    this->total_sales=total_sales;
}
Customer::Customer(string record)
{
    istringstream line(record);
    getline(line,this->customer_id,'\t');
    getline(line,this->username,'\t');
    getline(line,this->first_name,'\t');
    getline(line,this->last_name,'\t');
    getline(line,this->street_address,'\t');
    getline(line,this->city,'\t');
    getline(line,this->state,'\t');
    getline(line,this->postal_code,'\t');
    getline(line,this->email_address,'\t');
    getline(line,this->gender,'\t');
    getline(line,this->company,'\t');
    getline(line,this->job_title,'\t');
    string date_since;
    getline(line,date_since,'\t');
    Date since(date_since);
    this->customer_since=since;
    getline(line,this->social_security_number,'\t');
    string birthday;
    getline(line,birthday,'\t');
    Date birth(birthday);
    this->date_of_birth=birth;
    string household;
    getline(line,household,'\t');
    this->household_income=stoi(household);
    string credit;
    getline(line,credit,'\t');
    this->credit_score=stoi(credit);
    string sales;
    getline(line,sales);
    this->total_sales=stod(sales);
}
void Customer::setUserName(string userName) {
    username=userName;
}
string Customer::getUserName() const
{
    return username;
}
string Customer::getFirstName() const {
    return first_name;
}

void Customer::setFirstName(string firstName) {
    first_name=firstName;
}

string Customer::getLastName() const {
    return last_name;
}
void Customer::setLastName(string lastName) {
    last_name=lastName;
}

string Customer::getStreetAddress() const {
    return street_address;
}
void Customer::setStreetAddress(string streetAddress) {
    street_address=streetAddress;
}

string Customer::getCity() const {
    return city;
}
void Customer::setCity(string city) {
    this->city=city;
}

string Customer::getState() const {
    return state;
}

void Customer::setState(string state) {
    this->state=state;
}
string Customer::getZip() const {
    return postal_code;
}

void Customer::setZip(string zip) {
    postal_code=zip;
}

string Customer::getEmail() const {
    return email_address;
}

void Customer::setEmail(string email) {
    email_address=email;
}

string Customer::getGender() const {
    return gender;
}

void Customer::setGender(string gender) {
    this->gender=gender;
}

string Customer::getCompany() const {
    return company;
}

void Customer::setCompany(string company) {
    this->company=company;
}

string Customer::getJobTitle() const {
    return job_title;
}

void Customer::setJobTitle(string jobTitle) {
    job_title=jobTitle;
}
Date Customer::getCustomerSince() const {
    return customer_since;
}
void Customer::setCustomerSince(Date customerSince) {
   customer_since=customerSince;
}

Date Customer::getDateOfBirth() const {
    return date_of_birth;
}
void Customer::setDateOfBirth(Date dateOfBirth) {
    date_of_birth=dateOfBirth;
}

int Customer::getHouseholdIncome() const {
    return household_income;
}

void Customer::setHouseholdIncome(int householdIncome) {
    household_income=householdIncome;
}

int Customer::getCreditScore() const {
    return credit_score;
}

void Customer::setCreditScore(int creditScore) {
    credit_score=creditScore;
}
double Customer::getTotalSales() const {
    return total_sales;
}
void Customer::setTotalSales(double totalSales) {
    total_sales=totalSales;
}
string Customer::getCustomerID() const{
    return customer_id;
}
void Customer::setCustomerID(string basicString) {
    customer_id=basicString;
}

string Customer::getSocialSecurityNumber() {
    return social_security_number;
}

void Customer::setSocialSecurityNumber(string social_security_number) {
    this->social_security_number=social_security_number;
}

CustomerCompareOptions Customer::getCompareWith()
{
    return option;
}

void Customer::setCompareWith(CustomerCompareOptions code)
{
    option=code;
}
//set to fullname by default
void Customer::setCompareWith()
{
    option=FullName;
}
bool Customer::operator==(const Customer &lhs) const
{
    int opt = Customer::getCompareWith();
    switch (opt) {
        case FullName:
            if (this->last_name==lhs.getLastName()&& this->first_name==lhs.getFirstName()) {
                return true;}
           else {
                return false;
            }
        case UserName:
            if (this->getUserName()==lhs.getUserName()) {
                return true;
            } else {
                return false;
            }
        case CustomerID:
            if (this->getCustomerID()==lhs.getCustomerID()) {
                return true;
            } else {
                return false;
            }
        case CustomerSince:
            if(this->getCustomerSince()==lhs.getCustomerSince())
            {
                return true;
            }
            else
            {
                return false;
            }
        case DateOfBirth:
            if(this->getDateOfBirth()==lhs.getDateOfBirth())
            {
                return true;
            }
            else
            {
                return false;
            }
        case CreditScore:
            if (this->getCreditScore() == lhs.getCreditScore()) {
                return true;
            } else {
                return false;
            }
        case HouseholdIncome:
            if (this->getHouseholdIncome() == lhs.getHouseholdIncome()) {
                return true;
            } else {
                return false;
            }
        case TotalSales: //left with TotalSales
            if (this->getTotalSales() == lhs.getTotalSales()) {
                return true;
            } else {
                return false;
            }
    }
    return true;
}

bool Customer::operator!=(const Customer &lhs) const
{
    if (*this==lhs) {return false;}
    else {return true;}
}
// compare by fullname
// compare function is used to compare order alphabetically of two stings
// a.compare(b) > 0 -> a>b and vice versa
// a.compare(b) == 0 ->a =b
bool Customer::operator<(const Customer &lhs) const {
    int opt = Customer::getCompareWith();
    switch (opt) {
        case FullName:
            if (this->last_name.compare(lhs.getLastName()) < 0) {
                return true;
            } else if (this->last_name.compare(lhs.getLastName()) == 0) {
                if (this->first_name.compare(lhs.getFirstName()) < 0) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        case UserName:
            if (this->getUserName().compare(lhs.getUserName()) < 0) {
                return true;
            } else {
                return false;
            }
        case CustomerSince:
            if(this->getCustomerSince()<lhs.getCustomerSince())
            {
                return true;
            }
            else
            {
                return false;
            }
        case DateOfBirth:
            if(this->getDateOfBirth()<lhs.getDateOfBirth())
            {
                return true;
            }
            else
            {
                return false;
            }
        case CreditScore:
            if (this->getCreditScore() < lhs.getCreditScore()) {
                return true;
            } else {
                return false;
            }
        case HouseholdIncome:
            if (this->getHouseholdIncome() < lhs.getHouseholdIncome()) {
                return true;
                break;
            } else {
                return false;
                break;
            }
        case TotalSales: //left with TotalSales
            if (this->getTotalSales() < lhs.getTotalSales()) {
                return true;
            } else {
                return false;
            }

    }
    return true;
}
bool Customer::operator<=(const Customer &lhs) const
{
    if (*this<lhs|| *this==lhs)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Customer::operator>(const Customer &lhs) const
{
    return !(*this<=lhs);
}
bool Customer::operator>=(const Customer &lhs) const
{
    return !(*this<lhs);
}
string Customer::toString() const
{
    string result=this->getFirstName() + " " + this->getLastName() + " (" + this->getCustomerID() + ")" + " " + to_string(this->getCreditScore());
    return result;
}
ostream & operator << (ostream &out, const Customer &customer)
{
    out << customer.toString();
    return out;
}
bool Customer::operator=(const Customer &lhs)
{
    this->customer_id=lhs.getCustomerID();
    this->username=lhs.getUserName();
    this->first_name=lhs.getFirstName();
    this->last_name=lhs.getLastName();
    this->street_address=lhs.getStreetAddress();
    this->city=lhs.getCity();
    this->state=lhs.getState();
    this->postal_code=lhs.getZip();
    this->email_address=lhs.getEmail();
    this->gender=lhs.getGender();
    this->company=lhs.getCompany();
    this->job_title=lhs.getJobTitle();
    this->customer_since=lhs.getCustomerSince();
    this->social_security_number=lhs.social_security_number;
    this->date_of_birth=lhs.date_of_birth;
    this->household_income=lhs.household_income;
    this->credit_score=lhs.credit_score;
    this->total_sales=lhs.total_sales;
}