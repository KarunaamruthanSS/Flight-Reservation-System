#include<fstream>
#include<cstring>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<cstdlib>
#include<ctime>
#include"flightDetails.h"
#include"BookingDetails.h"
using namespace std;

BookingDetails passengerDetails[100];

BookingDetails::BookingDetails()
{
    strcpy(this->passengerName,"name");
    strcpy(this->state,"tamilnadu");
    strcpy(this->phoneNo,"900000");
    strcpy(this->city,"CDL");
    strcpy(this->street,"sdr");
    passengerNo=0;
    doorNo=0;
    seatCount=0;
    classType=0;
}

BookingDetails::BookingDetails(char tsource[],char tdestination[],char flightNum[],char tpassengerName[],char tstate[],char tcity[],char tstreet[],char tphoneNo[],int tpassengerNo,int tDoorNo,int tseatCount,int tclassType):TravelDetails(tsource,tdestination,flightNum)
{
    strcpy(this->passengerName,tpassengerName);
    strcpy(this->state,tstate);
    strcpy(this->street,tstreet);
    strcpy(this->phoneNo,tphoneNo);
    strcpy(this->city,tcity);
    this->passengerNo=tpassengerNo;
    this->doorNo=tDoorNo;
    this->seatCount=tseatCount;
    this->classType=tclassType;
}

BookingDetails::BookingDetails(const BookingDetails& obj)
{
    strcpy(this->passengerName,obj.passengerName);
    strcpy(this->state,obj.state);
    strcpy(this->street,obj.street);
    strcpy(this->phoneNo,obj.phoneNo);
    strcpy(this->city,obj.city);
    this->passengerNo=obj.passengerNo;
    this->doorNo=obj.doorNo;
    this->seatCount=obj.seatCount;
    this->classType=classType;
}

void BookingDetails::setPassengerName(char name[])
{
    strcpy(this->passengerName,name);
}

void BookingDetails::setDoorNo(int doorNo)
{
    this->doorNo=doorNo;
}

void BookingDetails::setPhoneNo(char phone[])
{
    strcpy(this->phoneNo,phone);
}

void BookingDetails::setState(char state[])
{
    strcpy(this->state,state);
}

void BookingDetails::setCity(char city[])
{
    strcpy(this->city,city);
}

void BookingDetails::setStreet(char street[])
{
    strcpy(this->street,street);
}

void BookingDetails::setPassengerNo(int passNo)
{
    this->passengerNo=passNo;
}

void BookingDetails::setClassType(int tclassType)
{
    this->classType=tclassType;
}

void BookingDetails::setSeatCount(int seat)
{
    this->seatCount=seat;
}

int BookingDetails::getPassengerNo() const
{
    return this->passengerNo;
}

int BookingDetails::getDoorNo() const
{
    return this->doorNo;
}

int BookingDetails::getSeatCount() const
{
    return this->seatCount;
}

int BookingDetails::getClassType() const
{
    return this->classType;
}

const char* BookingDetails::getPassengerName() const
{
    return this->passengerName;
}

const char* BookingDetails::getPhoneNo() const
{
    return this->phoneNo;
}

const char* BookingDetails::getState() const
{
    return this->state;
}

const char* BookingDetails::getStreet() const
{
    return this->street;
}

const char* BookingDetails::getCity() const
{
    return this->city;
}

BookingDetails passengers[500];
static int passengerCount=0;

void readFromFile()
{
    passengerCount=0;
    fstream file;
    file.open("booking.txt",ios::binary|ios::in);
    while(file.read((char*)(&passengers[passengerCount]),sizeof(passengers[passengerCount])))
    {
        passengerCount++;
    }
    file.close();
}

void checkSeatCount(int& noOfSeats)
{
    int seats=0;
    if(noOfSeats>10  || noOfSeats<=0)
    {
        cout<<"One person can book only 10 seats at a time"<<endl;
        cout<<"Enter the seat count again: "<<endl;
        cin>>seats;
        cin.ignore(1,'\n');
        checkSeatCount(seats);
        noOfSeats=seats;
    }
}

void BookingDetails::passengerDetails()
{
    char passengerName[50];
    char state[50];
    char street[50];
    char city[50];
    char phoneNo[50];
    int doorNo=0;
    int passengerNo=0,seatCount=0;
    cin.ignore(1,'\n');
    cout<<"Enter the passenger name: "<<endl;
    cin.getline(passengerName,50);
    cout<<"Enter the state: "<<endl;
    cin.getline(state,50);
    cout<<"Enter the city: "<<endl;
    cin.getline(city,50);
    cout<<"Enter the street: "<<endl;
    cin.getline(street,50);
    cout<<"Enter the Door Number: "<<endl;
    cin>>doorNo;
    cout<<"Enter the seat count: "<<endl;
    cin>>seatCount;
    checkSeatCount(seatCount);
    cin.ignore(1,'\n');
    cout<<"Enter the Phone Number: "<<endl;
    cin.getline(phoneNo,50);
    passengers[passengerCount].setPassengerName(passengerName);
    passengers[passengerCount].setState(state);
    passengers[passengerCount].setCity(city);
    passengers[passengerCount].setStreet(street);
    passengers[passengerCount].setPhoneNo(phoneNo);
    passengers[passengerCount].setDoorNo(doorNo);
    passengers[passengerCount].setSeatCount(seatCount);
    srand(time(0));
    passengerNo=(rand()%(99999-10000+1)+10000);
    passengers[passengerCount].setPassengerNo(passengerNo);
    fstream file;
    file.open("booking.txt",ios::binary|ios::app);
    file.write((char*)(&passengers[passengerCount]),sizeof(passengers[passengerCount]));
    file.close();
    passengers[passengerCount].display(passengers[passengerCount]);
    passengerCount++;
}

void BookingDetails::totalDisplay()
{
    readFromFile();
    for(int i=0; i<passengerCount; i++)
    {
        passengers[i].display(passengers[i]);
    }
}

void BookingDetails::display(BookingDetails& obj)
{
    cout<<"========================================================================================"<<endl;
    cout<<"\t\t\t\t******BILL*******\t\t\t\t"<<endl;
    cout<<"========================================================================================"<<endl;
    cout<<"PASSENGER NAME       : "<<obj.getPassengerName()<<"\t\t\t\tPASSENGER NUMBER:"<<obj.getPassengerNo()<<endl;
    cout<<"SOURCE               : "<<obj.getSource()<<"\t\t\t\t\tDESTINATION:"<<obj.getDestination()<<endl;
    cout<<"SEAT COUNT           : "<<obj.getSeatCount()<<endl;
    cout<<"DOOR NO              : "<<obj.getDoorNo()<<endl;
    cout<<"ADDRESS\n\t\t\t"<<obj.getDoorNo()<<','<<obj.getStreet()<<"\n\t\t\t"<<obj.getCity()<<"\n\t\t\t"<<obj.getState()<<endl;
}

int BookingSearch(char source[],char des[],FlightDetails& temp1)
{
    int choice=0,noOfSeats=0,flag=0,i=0,flightCount=0;
    char flightNum[50];
    strcpy(flightNum,temp1.getFlightNo());

    cout<<"Press 1 for Economy Class"<<endl;
    cout<<"Press 2 for Business Class"<<endl;
    cout<<"Press 3 for First Class"<<endl;
    cin>>choice;

    if(choice==1)
    {
        passengers[passengerCount].passengerDetails();
        temp1.updateAvailableSeats(choice,passengers[passengerCount-1].getSeatCount(),source,des,flightNum);
        cout<<"========================================================================================"<<endl;
        cout<<"Price of one ticket           \t\t\t\t\t: "<<fixed<<setprecision(2)<<temp1.getEconomyClassPrice()<<endl;
        cout<<"******GRAND TOTAL*****        \t\t\t\t\t: "<<fixed<<setprecision(2)<<temp1.getEconomyClassPrice()*passengers[passengerCount-1].getSeatCount()<<endl;
        cout<<"========================================================================================"<<endl;
        flag=1;
    }

    else if(choice==2)
    {
        passengers[passengerCount].passengerDetails();
        temp1.updateAvailableSeats(choice,passengers[passengerCount-1].getSeatCount(),source,des,flightNum);
        cout<<"========================================================================================"<<endl;
        cout<<"Price of one ticket  \t\t\t\t: "<<fixed<<setprecision(2)<<temp1.getBusinessClassPrice()<<endl;
        cout<<"Total Amount         \t\t\t\t: "<<fixed<<setprecision(2)<<temp1.getBusinessClassPrice()*passengers[passengerCount-1].getSeatCount()<<endl;
        cout<<"========================================================================================"<<endl;
        flag=1;
    }

    else if(choice==3)
    {
        passengers[passengerCount].passengerDetails();
        temp1.updateAvailableSeats(choice,passengers[passengerCount-1].getSeatCount(),source,des,flightNum);
        cout<<"========================================================================================"<<endl;
        cout<<"Price of one ticket  \t\t\t\t: "<<fixed<<setprecision(2)<<temp1.getFirstClassPrice()<<endl;
        cout<<"Total Amount         \t\t\t\t: "<<fixed<<setprecision(2)<<temp1.getFirstClassPrice()*passengers[passengerCount-1].getSeatCount()<<endl;
        cout<<"========================================================================================"<<endl;
        flag=1;
    }
    return flag;
}

void BookingDetails::bookingTicket(char source[],char des[])
{
    int choice=0,noOfSeats=0,flag=0,i=0,flightCount=0;
    char flightNum[50];
    FlightDetails temp1;
    readFromFile();
    passengers[passengerCount].setSource(source);
    passengers[passengerCount].setDestination(des);
    if(temp1.searching(source,des,temp1)==1)
    {
        flag=BookingSearch(source,des,temp1);
    }
    else if(temp1.searching(source,des,temp1)==2)
    {
        int x=0;
        cout<<"Enter the flight Number to search: "<<endl;
        cin.getline(flightNum,50);
        x=temp1.searchFlightNo(flightNum,temp1);
        flag=BookingSearch(source,des,temp1);
    }
    else
    {
        cout<<"Flight Not Found"<<endl;
        flag=0;
    }
}

void BookingDetails::ticketDisplay(int tpassengerNo)
{
    readFromFile();
    for(int i=0; i<passengerCount; i++)
    {
        if(tpassengerNo==passengers[i].getPassengerNo())
        {
            passengers[i].display(passengers[i]);
        }
    }
}

void BookingDetails::cancellation(int tpassengerNo)
{
    readFromFile();
    FlightDetails temp1;
    FlightDetails temp;
    char source[50];
    char destination[50];
    char flightNum[50];
    int flag=0;
    fstream file2;
    file2.open("passengerDetails.txt",ios::binary|ios::out);
    for(int i=0; i<passengerCount; i++)
    {
        if(tpassengerNo==passengers[i].getPassengerNo())
        {
            strcpy(source,passengers[i].getSource());
            strcpy(destination,passengers[i].getDestination());
            /*if(temp1.searching(source,destination,temp1)==1)
            {
                flag=BookingSearch(source,destination,temp1);
            }
            else if(temp1.searching(source,destination,temp1)==2)
            {
                int x=0;
                cout<<"Enter the flight Number to search: "<<endl;
                cin.getline(flightNum,50);
                x=temp1.searchFlightNo(flightNum,temp1);
                flag=BookingSearch(source,destination,temp1);
            }
            else
            {
                cout<<"Flight Not Found"<<endl;
                flag=0;
            }*/
            strcpy(flightNum,passengers[i].getFlightNo());
            cout<<passengers[i].getFlightNo()<<'\t'<<flightNum<<endl;
            int seats=0;
            seats=(-1)*passengers[i].getSeatCount();
            temp.updateAvailableSeats(passengers[i].getClassType(),seats,source,destination,flightNum);
            passengerCount--;
        }
        else
        {
            file2.write((char*)(&passengers[i]),sizeof(passengers[i]));
            passengers[i].display(passengers[i]);
        }
    }
    file2.close();

    remove("booking.txt");
    rename("passengerDetails.txt","booking.txt");
}

bool BookingDetails::operator==(BookingDetails& obj2)
{
    if(this->passengerNo==obj2.passengerNo && this->passengerName==obj2.passengerName)
        return 1;

    else
        return 0;
}
