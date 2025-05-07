#include<iostream>
#include"ExistingLogin.h"
#include<fstream>
using namespace std;
ExistingLogin::ExistingLogin():name(""),password("")
{
}
ExistingLogin::ExistingLogin(string tname,string tpassword):name(tname),password(tpassword){
}
ExistingLogin::ExistingLogin(const ExistingLogin& euser)
{
    this->name=euser.name;
    this->password=euser.password;
}
string ExistingLogin::getName()
{
    return name;
}
string ExistingLogin::getPassword()
{
    return password;
}
void ExistingLogin::setName(string name)
{
    this->name=name;
}
void ExistingLogin::setPassword(string password)
{
    this->password=password;
}
bool ExistingLogin::namecheck(string name)
{
    if(this->name==name)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
