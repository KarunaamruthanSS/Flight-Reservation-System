#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
#include<cstring>
#include<string.h>
#include"flightDetails.h"
#include"flightDetails.cpp"
#include"Admin.h"
#include"Admin.cpp"
#include"ExistingLogin.h"
#include"ExistingLogin.cpp"
#include"NewLogin.h"
#include"NewLogin.cpp"
//#include"PassengerDetails.h"
//#include"PassengerDetails.cpp"
#include"BookingDetails.h"
#include"BookingDetails.cpp"
#include"travelDetails.h"
#include"travelDetails.cpp"
#include <unistd.h>
using namespace std;
//FlightDetails flights[100];
//static int flightCount=0;
int userNameSearching(string user,string pWord)
{
    string line,line2;
    fstream file1;
    file1.open("login.txt",ios::in);
    stringstream line1(line);
    int i=0,flag=0;
    while(!file1.eof())
    {
        getline(file1,line,'\n');
        getline(file1,line2,'\n');
        if(line==user && line2==pWord)
        {
            flag=1;
            cout<<"Login Successfully"<<endl;
            break;
        }
    }
    if(flag!=0)
    {
        file1.close();
        return 1;
    }

    else
    {
        file1.close();
        return 0;
    }

}
int main()
{

    int opt=-1,i=0,br=0,n=6,size1=0;
    string topt;
    while(1)
    {
        while(opt!=1&&opt!=2&&opt!=0)
        {
            system("cls");
            cout<<"1.Admin\n2.User\n0.exit\nEnter your option:";
            cin>>topt;
            try
            {
                for(i=0; i<topt.length(); i++)
                {
                    if((topt[i]-'0')>9 || (topt[i]-'0')<0)
                    {
                        throw 0;
                    }

                    else
                    {
                        opt=(topt[i]-48);
                    }
                }
            }
            catch(int xa)
            {
                cout<<"Invalid Input"<<endl;
                sleep(1);
            }
        }
        char srce[50],des[50];
        string temp,temp1;
        fstream file;
        file.open("flight.txt",ios::binary|ios::in);
        while(file.read((char*)(&flights[flightCount]),sizeof(flights[flightCount])))
        {
            flightCount++;
        }
        file.close();
        if(opt==0)
        {
            break;
        }
        if(opt==1)
        {
            system("cls");
            cout<<"Enter the Admin name:";
            cin>>temp;
            if(temp=="0")
            {
                system("cls");
                opt=-1;
                continue;
            }
            while(1)
            {
                Admin a1;
                if(a1.namecheck(temp))
                {
                    while(1)
                    {
                        cout<<"Enter the password:";
                        cin>>temp;
                        if(temp=="0")
                        {
                            system("cls");
                            opt=-1;
                            break;
                        }
                        if(a1.passwordcheck(temp))
                        {
                            while(1)
                            {
                                opt=-1;
                                br=0;
                                FlightDetails flight;
                                while(opt!=1&&opt!=2&&opt!=3&&opt!=4&&opt!=0)
                                {
                                    system("cls");
                                    cout<<"\n\t\t\t\t\t|-----------------------------------|"<<endl;
                                    cout<<"\t\t\t\t\t|***FLIGHT RESERVATION SYSTEM ***   |"<<endl;
                                    cout<<"\t\t\t\t\t|-----------------------------------|"<<endl;
                                    cout<<"\t\t\t\t\t| 1. Add Flight                     |"<<endl;
                                    cout<<"\t\t\t\t\t| 2. Delete Flight                  |"<<endl;
                                    cout<<"\t\t\t\t\t| 3. Display Flight                 |"<<endl;
                                    cout<<"\t\t\t\t\t| 4. Search Flight                  |"<<endl;
                                    cout<<"\t\t\t\t\t| 0. Exit                           |"<<endl;
                                    cout<<"\t\t\t\t\t|.................................. |"<<endl;
                                    cout<<"\t\t\t\t\t|*** Choice Options: [1/2/3/4/0] ***|"<<endl;
                                    cout<<"\t\t\t\t\t|...................................-_-|"<<endl;
                                    cout<<"\t\t\t\t\t Enter Your Choice: ";
                                    cin>>topt;
                                    try
                                    {
                                        for(i=0; i<topt.length(); i++)
                                        {
                                            if((topt[i]-'0')>9 || (topt[i]-'0')<0)
                                            {
                                                throw 0;
                                            }

                                            else
                                            {
                                                opt=(topt[i]-48);
                                            }
                                        }
                                    }
                                    catch(int xa)
                                    {
                                        cout<<"Invalid Input"<<endl;
                                        sleep(1);
                                    }
                                }
                                switch(opt)
                                {
                                case 0:
                                    br=1;
                                    break;
                                case 1:
                                {
                                    cin.ignore(256, '\n');
                                    cout<<"Enter the source: "<<endl;
                                    cin.getline(srce,50);
                                    string s(srce);
                                    if(s.find("0")<=s.length())
                                    {
                                        br=1;
                                        break;
                                    }
                                    cout<<"Enter the destination: "<<endl;
                                    cin.getline(des,50);
                                    string d(des);
                                    if(d.find("0")<=d.length())
                                    {
                                        br=1;
                                        break;
                                    }
                                    flight.addFlight(srce,des,flights,size1);
                                    break;
                                }
                                case 2:
                                {
                                    cin.ignore(256, '\n');
                                    cout<<"Enter the source: "<<endl;
                                    cin.getline(srce,50);
                                    string s(srce);
                                    if(s.find("0")<=s.length())
                                    {
                                        br=1;
                                        break;
                                    }
                                    cout<<"Enter the destination: "<<endl;
                                    cin.getline(des,50);
                                    string d(des);
                                    if(d.find("0")<=d.length())
                                    {
                                        br=1;
                                        break;
                                    }
                                    flight.deleteFlight(srce,des,flights,size1);
                                    break;
                                }
                                case 3:
                                {
                                    flight.display(flights,size1);
                                    string alpha;
                                    int intalpha=1;
                                    while(intalpha!=0)
                                    {
                                        cout<<"Press zero to exit:";
                                        cin>>alpha;
                                        try
                                        {
                                            for(i=0; i<alpha.length(); i++)
                                            {
                                                if((alpha[i]-'0')>9 || (alpha[i]-'0')<0)
                                                {
                                                    throw 0;
                                                }

                                                else
                                                {
                                                    intalpha=(alpha[i]-48);
                                                }
                                            }
                                        }
                                        catch(int xa)
                                        {
                                            cout<<"Invalid Input"<<endl;
                                        }
                                    }
                                    break;
                                }
                                case 4:
                                {
                                    cin.ignore(256, '\n');
                                    cout<<"Enter the source: "<<endl;
                                    cin.getline(srce,50);
                                    string s(srce);
                                    if(s.find("0")<=s.length())
                                    {
                                        br=1;
                                        break;
                                    }
                                    cout<<"Enter the destination: "<<endl;
                                    cin.getline(des,50);
                                    string d(des);
                                    if(d.find("0")<=d.length())
                                    {
                                        br=1;
                                        break;
                                    }
                                    n=flight.searching(srce,des,flight);
                                    cout<<n<<endl;
                                    break;
                                }
                                }
                                if(br==1)
                                    break;
                            }
                        }
                        if(br==1)
                            break;
                    }
                    break;
                }
            }
        }
        if(opt==2)
        {
            while(1)
            {
                opt=-1;
                while(opt!=1&&opt!=2&&opt!=0)
                {
                    system("cls");
                    cout<<"1.Existing user\n2.New user\n0.Exit\nEnter your option:";
                    cin>>topt;
                    try
                    {
                        for(i=0; i<topt.length(); i++)
                        {
                            if((topt[i]-'0')>9 || (topt[i]-'0')<0)
                            {
                                throw 0;
                            }

                            else
                            {
                                opt=(topt[i]-48);
                            }
                        }
                    }
                    catch(int xa)
                    {
                        cout<<"Invalid Input"<<endl;
                        sleep(1);
                    }
                }
                if(opt==0)
                {
                    system("cls");
                    opt=-1;
                    break;
                }
                if(opt==2)
                {
                    NewLogin n1;
                    int nm=0;
                    cout<<"Enter the user name:";
                    cin>>temp;
                    if(temp=="0")
                    {
                        system("cls");
                        opt=-1;
                        continue;
                    }
                    n1.setNewName(temp);
                    fstream logobj;
                    logobj.open("login.txt",ios::in);
                    while(logobj.eof())
                    {
                        ExistingLogin e1;
                        getline(logobj,temp);
                        e1.setName(temp);
                        getline(logobj,temp);
                        e1.setPassword(temp);
                        if(e1.namecheck(n1.getNewName()))
                        {
                            cout<<"user name already exists"<<endl;
                            nm=1;
                            break;
                        }
                    }
                    if(nm==0)
                    {
                        logobj.close();
                        logobj.open("login.txt",ios::app);
                        string a;
                        int inta=1;
                        cout<<"Enter your password:";
                        cin>>temp;
                        if(temp=="0")
                        {
                            system("cls");
                            opt=-1;
                            continue;
                        }
                        n1.setNewPassword(temp);
                        logobj<<"\n"<<n1.getNewName()<<endl<<n1.getNewPassword();
                        logobj.close();
                        while(inta!=0)
                        {
                            cout<<"Enter 0 (zero) to exit:";
                            cin>>a;
                            try
                            {
                                for(i=0; i<a.length(); i++)
                                {
                                    if((a[i]-'0')>9 || (a[i]-'0')<0)
                                    {
                                        throw 0;
                                    }

                                    else
                                    {
                                        inta=(a[i]-48);
                                    }
                                }
                            }
                            catch(int xa)
                            {
                                cout<<"Invalid Input"<<endl;
                            }
                        }
                        //break;
                    }
                    if(nm==1)
                    {
                        break;
                    }
                }
                if(opt==1)
                {
                    while(1)
                    {
                        system("cls");
                        cout<<"Enter the username:";
                        cin>>temp;
                        if(temp=="0")
                        {
                            system("cls");
                            opt=-1;
                            break;
                        }
                        cout<<"Enter the password:";
                        cin>>temp1;
                        if(temp1=="0")
                        {
                            system("cls");
                            opt=-1;
                            break;
                        }
                        if(userNameSearching(temp,temp1))
                        {
                            while(opt!=0)
                            {
                                FlightDetails flight;
                                BookingDetails booking;

                                cout<<"\n\t\t\t\t\t|-----------------------------------|"<<endl;
                                cout<<"\t\t\t\t\t|***FLIGHT RESERVATION SYSTEM ***   |"<<endl;
                                cout<<"\t\t\t\t\t|-----------------------------------|"<<endl;
                                cout<<"\t\t\t\t\t| 1. Search Flight                  |"<<endl;
                                cout<<"\t\t\t\t\t| 2. Book Ticket                    |"<<endl;
                                cout<<"\t\t\t\t\t| 3. Display Flight                 |"<<endl;
                                cout<<"\t\t\t\t\t| 4. Display Booked ticket          |"<<endl;
                                cout<<"\t\t\t\t\t| 5. Cancellation of ticket         |"<<endl;
                                cout<<"\t\t\t\t\t| 0. Exit                           |"<<endl;
                                cout<<"\t\t\t\t\t|.................................. |"<<endl;
                                cout<<"\t\t\t\t\t|*** Choice Options: [1/2/3/4/5/0] ***|"<<endl;
                                cout<<"\t\t\t\t\t|...................................-_-|"<<endl;
                                cout<<"\t\t\t\t\t Enter Your Choice: ";
                                cin>>opt;
                                switch(opt)
                                {
                                case 0:
                                    break;
                                case 1:
                                    cin.ignore(1,'\n');
                                    cout<<"Enter the source of the flight: "<<endl;
                                    cin.getline(srce,50);
                                    cout<<"Enter the destination of the flight: "<<endl;
                                    cin.getline(des,50);
                                    flight.searching(srce,des,flight);
                                    break;
                                case 2:
                                    cout<<"Enter the source of the flight: "<<endl;
                                    cin.ignore(1,'\n');
                                    cin.getline(srce,50);
                                    cout<<"Enter the destination of the flight: "<<endl;
                                    cin.getline(des,50);
                                    booking.bookingTicket(srce,des);
                                    break;
                                case 3:
                                {
                                    flight.display(flights,size1);
                                    string alpha;
                                    int intalpha=1;
                                    while(intalpha!=0)
                                    {
                                        cout<<"Press zero to exit:";
                                        cin>>alpha;
                                        try
                                        {
                                            for(i=0; i<alpha.length(); i++)
                                            {
                                                if((alpha[i]-'0')>9 || (alpha[i]-'0')<0)
                                                {
                                                    throw 0;
                                                }

                                                else
                                                {
                                                    intalpha=(alpha[i]-48);
                                                }
                                            }
                                        }
                                        catch(int xa)
                                        {
                                            cout<<"Invalid Input"<<endl;
                                        }
                                    }
                                    break;
                                }
                                case 4:
                                {
                                    int ticketNo;
                                    //BookingDetails ticket;
                                    cout<<"Enter the ticket booking number:";
                                    //cin.ignore(1,'\n');
                                    cin>>ticketNo;
                                    booking.ticketDisplay(ticketNo);
                                    break;
                                }
                                case 5:
                                {
                                    int passengerNo=0;
                                    cout<<"Enter the passenger Number to cancellation of ticket: "<<endl;
                                    cin>>passengerNo;
                                    booking.cancellation(passengerNo);
                                    break;
                                }
                                }
                            }
                        }
                        else
                        {
                            cout<<"Check user name and password"<<endl;
                            sleep(1);
                        }
                    }
                }
            }
        }
        opt=-1;
    }
}
