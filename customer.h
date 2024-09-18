//
// Created by Nguyên Nguyễn on 9/15/23.
//
#include <string>
#include "date.h"
#ifndef LAB1_CUSTOMER_CUSTOMER_H
#define LAB1_CUSTOMER_CUSTOMER_H
using namespace std;
enum CustomerCompareOptions {CustomerID,FullName, UserName, CustomerSince, DateOfBirth, CreditScore, HouseholdIncome, TotalSales};
class Customer{
private:
    string customer_id;
    string username;
    string first_name;
    string last_name;
    string street_address;
    string city;
    string state;
    string postal_code;
    string email_address;
    string gender;
    string company;
    string job_title;
    Date customer_since;
    string social_security_number;
    Date date_of_birth;
    int household_income;
    int credit_score;
    double total_sales;
    static enum CustomerCompareOptions option;
public:
    // constructors
    Customer();
    Customer(string customer_id, string username, string first_name, string last_name,
             string street_address, string city, string state, string zip,
             string email, string gender, string company, string job_title, Date customer_since,
             string social_security_number, Date date_of_birth, int household_income,
             int credit_score, double total_sales);
    Customer(string record);
    // getters and setters
    void setCustomerID(string basicString);
    string getCustomerID() const;
    void setUserName(string userName);
    string getUserName() const;
    string getFirstName() const;
    void setFirstName(string firstName);
    string getLastName() const;
    void setLastName(string lastName);
    string getStreetAddress() const;
    void setStreetAddress(string streetAddress);
    string getCity() const;
    void setCity(string city);
    string getState() const;
    void setState(string state);
    string getZip() const;
    void setZip(string zip);
    string getEmail() const;
    void setEmail(string email);
    string getGender() const;
    void setGender(string gender);
    string getCompany() const;
    void setCompany(string company);
    string getJobTitle() const;
    void setJobTitle(string jobTitle);
    Date getCustomerSince() const;
    void setCustomerSince(Date customerSince);
    void setSocialSecurityNumber(string social_security_number);
    string getSocialSecurityNumber();
    Date getDateOfBirth() const;
    void setDateOfBirth(Date dateOfBirth);
    int getHouseholdIncome() const;
    void setHouseholdIncome(int householdIncome);
    int getCreditScore() const;
    void setCreditScore(int creditScore);
    double getTotalSales() const;
    void setTotalSales(double totalSales);
    static CustomerCompareOptions getCompareWith();
    static void setCompareWith(CustomerCompareOptions code);
    static void setCompareWith();
    bool operator=(const Customer &lhs) ;
    bool operator==(const Customer &lhs) const;
    bool operator!=(const Customer &lhs) const;
    bool operator<(const Customer &lhs) const;
    bool operator<=(const Customer &lhs)const ;
    bool operator>(const Customer &lhs) const;
    bool operator>=(const Customer &lhs) const;
    string toString() const;
};
ostream & operator << (ostream &out, const Customer &customer);
#endif //LAB1_CUSTOMER_CUSTOMER_H
