#ifndef EXISTINGLOGIN_H_INCLUDED
#define EXISTINGLOGIN_H_INCLUDED
#include<iostream>
using namespace std;
class ExistingLogin
{
    string name;
    string password;
public:
    ExistingLogin();
    ExistingLogin(string,string);
    ExistingLogin(const ExistingLogin&);
    string getName();
    string getPassword();
    void setName(string);
    void setPassword(string);
    bool namecheck(string);
};
#endif // EXISTINGLOGIN_H_INCLUDED
