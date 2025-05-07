#ifndef NEWLOGIN_H_INCLUDED
#define NEWLOGIN_H_INCLUDED
#include<iostream>
using namespace std;
class NewLogin
{
    string newName;
    string newPassword;
public:
    NewLogin();
    NewLogin(string,string);
    NewLogin(const NewLogin&);
    string getNewName();
    string getNewPassword();
    void setNewName(string);
    void setNewPassword(string);
};
#endif // NEWLOGIN_H_INCLUDED
