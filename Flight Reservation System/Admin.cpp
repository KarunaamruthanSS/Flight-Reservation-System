#include<iostream>
#include"Admin.h"
#include<fstream>
using namespace std;
Admin::Admin()
{
    ifstream file("adminlogin.txt");
    for(int i=0;i<2;i++)
    {
        getline(file,user);
        getline(file,password);
    }
}
Admin::Admin(string user,string password)
{
    this->user=user;
    this->password=password;
}
Admin::Admin(const Admin& obj)
{
    this->user=obj.user;
    this->password=obj.password;
}
string Admin::getUser()
{
    return user;
}
string Admin::getPassword()
{
    return password;
}
void Admin::setUser(string user)
{
    this->user=user;
}
void Admin::setPassword(string password)
{
    this->password=password;
}
bool Admin::namecheck(string tname)
{
    if(user==tname)
        return 1;
    else
        return 0;
}
bool Admin::passwordcheck(string tpassword)
{
    if(password==tpassword)
    {
        return 1;
    }
    else
        return 0;
}
