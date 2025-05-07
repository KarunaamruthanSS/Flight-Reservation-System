#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
#include<iostream>
using namespace std;
/*struct Address
{
    int doorNo;
    string streetName;
    string village;
    string city;
    string district;
    string state;
};*/
class Admin
{
    string user;
    string password;
public:
    Admin();
    Admin(string,string);
    Admin(const Admin&);
    string getUser();
    string getPassword();
    void setUser(string);
    void setPassword(string);
    bool namecheck(string);
    bool passwordcheck(string);
};
#endif // ADMIN_H_INCLUDED
