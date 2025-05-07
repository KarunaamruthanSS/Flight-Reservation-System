#include<iostream>
#include"NewLogin.h"
#include<fstream>
using namespace std;
NewLogin::NewLogin()
{
    newName="";
    newPassword="";
}
NewLogin::NewLogin(string name,string password)
{
    newName=name;
    newPassword=password;
}
NewLogin::NewLogin(const NewLogin& obj)
{
    this->newName=obj.newName;
    this->newPassword=obj.newPassword;
}
string NewLogin::getNewName()
{
    return newName;
}
string NewLogin::getNewPassword()
{
    return newPassword;
}
void NewLogin::setNewName(string name)
{
    this->newName=name;
}
void NewLogin::setNewPassword(string password)
{
    this->newPassword=password;
}
