#include<iostream>
#include<fstream>
#include<cstring>
#include<cctype>
#include<sstream>
#include<stack>
#include<iomanip>
#include<algorithm>
#include<string.h>
#include"flightDetails.h"
#include"BookingDetails.h"
#include"travelDetails.h"
using namespace std;

void checkDate(struct date&);
int flightCount=0;
FlightDetails flights[100];

FlightDetails::FlightDetails()
{
    strcpy(this->companyName,"Indigo");
    this->flightDate.day=0;
    this->flightDate.month=0;
    this->flightDate.year=0;
    this->timing=0;
    this->firstPrice=0;
    this->economyPrice=0;
    this->businessPrice=0;
    this->availableSeats=0;
    this->availableBusinessClass=0;
    this->availableEconomyClass=0;
    this->availableFirstClass=0;
    this->totalBusinessClass=0;
    this->totalEconomyClass=0;
    this->totalFirstClass=0;
    this->totalSeats=0;
}

FlightDetails::FlightDetails(char tsource[],char tdestination[],char tflightNo[],char tcompanyName[],struct date tdate,double ttiming,double tfirstPrice,double tbusinessPrice,double teconomyPrice,int tSeats,int aSeats,int bClass,int eClass,int fClass,int tBclass,int tEClass,int tFclass):TravelDetails(tsource,tdestination,tflightNo)
{
    strcpy(companyName,tcompanyName);
    flightDate=tdate;
    timing=ttiming;
    businessPrice=tbusinessPrice;
    economyPrice=teconomyPrice;
    firstPrice=tfirstPrice;
    availableSeats=aSeats;
    availableBusinessClass=bClass;
    availableEconomyClass=eClass;
    availableFirstClass=fClass;
    totalBusinessClass=tBclass;
    totalEconomyClass=tEClass;
    totalFirstClass=tFclass;
    totalSeats=tSeats;
}

FlightDetails::FlightDetails(const FlightDetails& obj)
{
    strcpy(this->companyName,obj.companyName);
    this->flightDate=obj.flightDate;
    this->timing=obj.timing;
    this->firstPrice=obj.firstPrice;
    this->businessPrice=obj.businessPrice;
    this->economyPrice=obj.economyPrice;
    this->availableSeats=obj.availableSeats;
    this->availableBusinessClass=obj.availableBusinessClass;
    this->availableEconomyClass=obj.availableEconomyClass;
    this->availableFirstClass=obj.availableFirstClass;
    this->totalBusinessClass=obj.totalBusinessClass;
    this->totalFirstClass=obj.totalFirstClass;
    this->totalEconomyClass=obj.totalEconomyClass;
    this->totalSeats=obj.totalSeats;
}

int FlightDetails::getAvailableSeats() const
{
    return this->availableSeats;
}

int FlightDetails::getTotalSeats() const
{
    return this->totalSeats;
}

int FlightDetails::getAvailableBusinessClass() const
{
    return this->availableBusinessClass;
}

int FlightDetails::getTotalBusinessClass() const
{
    return this->totalBusinessClass;
}

int FlightDetails::getAvailableEconomyClass() const
{
    return this->availableEconomyClass;
}

int FlightDetails::getTotalEconomyClass() const
{
    return this->totalEconomyClass;
}

int FlightDetails::getTotalFirstClass() const
{
    return this->totalFirstClass;
}

int FlightDetails::getAvailableFirstClass() const
{
    return this->availableFirstClass;
}

double FlightDetails::getTiming() const
{
    return this->timing;
}

double FlightDetails::getFirstClassPrice() const
{
    return this->firstPrice;
}

double FlightDetails::getEconomyClassPrice() const
{
    return this->economyPrice;
}

double FlightDetails::getBusinessClassPrice() const
{
    return this->businessPrice;
}

struct date FlightDetails::getDate() const
{
    return this->flightDate;
}

const char* FlightDetails::getCompanyName() const
{
    return this->companyName;
}


void FlightDetails::setCompanyName(char tcompanyName[])
{
    strcpy(companyName,tcompanyName);
}

void FlightDetails::setTiming(double ttiming)
{
    timing=ttiming;
}

void FlightDetails::setAvailableSeats(int tavailableSeats)
{
    this->availableSeats=tavailableSeats;
}

void FlightDetails::setTotalSeats(int ttotalSeats)
{
    this->totalSeats=ttotalSeats;
}

void FlightDetails::setDate(struct date tdate)
{
    this->flightDate.day=tdate.day;
    this->flightDate.month=tdate.month;
    this->flightDate.year=tdate.year;
}

void FlightDetails::setAvailableBusinessClass(int tavailableBusinessClass)
{
    this->availableBusinessClass=tavailableBusinessClass;
}

void FlightDetails::setTotalBusinessClass(int ttotalBusinessClass)
{
    this->totalBusinessClass=ttotalBusinessClass;
}

void FlightDetails::setAvailableEconomyClass(int tavailableEconomyClass)
{
    this->availableEconomyClass=tavailableEconomyClass;
}

void FlightDetails::setTotalEconomyClass(int ttotalEconomyClass)
{
    totalEconomyClass=ttotalEconomyClass;
}

void FlightDetails::setAvailableFirstClass(int tavailableFirstClass)
{
    availableFirstClass=tavailableFirstClass;
}

void FlightDetails::setTotalFirstClass(int ttotalFirstClass)
{
    totalFirstClass=ttotalFirstClass;
}

void FlightDetails::setBusinessClassPrice(double tPrice)
{
    businessPrice=tPrice;
}

void FlightDetails::setEconomyClassPrice(double tPrice)
{
    economyPrice=tPrice;
}

void FlightDetails::setFirstClassPrice(double tPrice)
{
    firstPrice=tPrice;
}

int checkFlightCapacity(int total,int business,int economy,int first)
{
    int sum=0;
    stack<int> arr;
    arr.push(business);
    arr.push(economy);
    arr.push(first);

    sum=sum+arr.top();
    arr.pop();
    sum=sum+arr.top();
    arr.pop();
    sum=sum+arr.top();
    arr.pop();

    if(total==sum)
        return 0;
    else
    {
        cout<<"Invalid Input Seat count is greater than total count"<<endl;
        return 1;
    }
}

int FlightDetails::searching(char srce[],char des[],FlightDetails& obj)
{
    int i=0,flag=0;
    int length=strlen(source)>strlen(des)?strlen(source):strlen(des);

    while(i<length)
    {
        source[i]=tolower(source[i]);
        des[i]=tolower(des[i]);
        i++;
    }

    i=0;
    while(i<flightCount)
    {
        if((strcmp(srce,flights[i].getSource())==0) && (strcmp(des,flights[i].getDestination())==0))
        {
            cout<<"Flight Found"<<endl;
            flights[i].flightDisplay(flights[i]);
            obj=flights[i];
            flag++;
        }
        i++;
        if(flag==1)
        {
            break;
        }
    }

    if(flag==0)
    {
        cout<<"Flight not Found change source and destination"<<endl;
        return 0;
    }

    else
    {
        return flag;
    }
}

int FlightDetails::searchFlightNo(char flightNo[],FlightDetails& temp)
{
    for(int i=0;i<flightCount;i++)
    {
        if(strcmp(flights[i].getFlightNo(),flightNo)==0)
        {
            cout<<flights[i].getFlightNo()<<endl;
            temp=flights[i];
            return 1;
        }
    }
    return 0;
}

ostream& operator<<(ostream& cout,const FlightDetails& obj1)
{
    cout<<setw(10)<<obj1.source<<setw(15)<<obj1.destination<<setw(15)<<obj1.flightNo<<setw(15)<<obj1.companyName<<setw(12)<<obj1.flightDate.day<<'/'<<setw(2)<<obj1.flightDate.month<<'/'<<setw(4)<<obj1.flightDate.year<<setw(10)<<obj1.timing<<setw(10)<<obj1.totalSeats<<setw(10)<<obj1.availableSeats<<endl;
    return cout;
}

FlightDetails& FlightDetails::operator=(FlightDetails& obj)
{
    strcpy(this->source,obj.source);
    strcpy(this->destination,obj.destination);
    strcpy(this->companyName,obj.companyName);
    this->flightDate=obj.flightDate;
    strcpy(this->flightNo,obj.flightNo);
    this->timing=obj.timing;
    this->firstPrice=obj.firstPrice;
    this->businessPrice=obj.businessPrice;
    this->economyPrice=obj.economyPrice;
    this->availableSeats=obj.availableSeats;
    this->availableBusinessClass=obj.availableBusinessClass;
    this->availableEconomyClass=obj.availableEconomyClass;
    this->availableFirstClass=obj.availableFirstClass;
    this->totalBusinessClass=obj.totalBusinessClass;
    this->totalFirstClass=obj.totalFirstClass;
    this->totalEconomyClass=obj.totalEconomyClass;
    this->totalSeats=obj.totalSeats;
    return *this;
}

void FlightDetails::addFlight(char source[],char des[],FlightDetails flights[],int& size1)
{
    char flightNo[50];
    char company[50];
    double time=0,price=0;
    FlightDetails obj1;
    int noOfSeats=0,totalBusinessClass=0,totalEconomyClass=0,totalFirstClass=0,i=0;
    int availableSeats=0,availableFirstClass=0,availableEconomyClass=0,availableBusinessClass=0,businessPrice=0,economyPrice=0,firstPrice=0;
    struct date tdate;

    flights[flightCount].setSource(source);
    flights[flightCount].setDestination(des);
    do
    {
    cout<<"Enter the flight number: "<<endl;
    cin.getline(flightNo,50);
    }while(flights[flightCount].searchFlightNo(flightNo,obj1)!=0);
    cout<<"Enter the flight's company name: "<<endl;
    cin.getline(company,50);
    cout<<"Enter the date of the flight: "<<endl;
    cout<<"Enter the day: "<<endl;
    cin>>tdate.day;
    cout<<"Enter the month: "<<endl;
    cin>>tdate.month;
    cout<<"Enter the year: "<<endl;
    cin>>tdate.year;
    checkDate(tdate);
    do
    {
        cout<<"Enter the departure timing of the flight: "<<endl;
        cin>>time;
    }while(time<0 || time>24);

    cout<<"Enter the total number of seats: "<<endl;
    cin>>noOfSeats;

    do
    {
    cout<<"Enter the total number of seats in business class: "<<endl;
    cin>>totalBusinessClass;
    cout<<"Enter the total number of seats in economy class: "<<endl;
    cin>>totalEconomyClass;
    cout<<"Enter the total number of seats in first class: "<<endl;
    cin>>totalFirstClass;
    }while(checkFlightCapacity(noOfSeats,totalBusinessClass,totalEconomyClass,totalFirstClass));
    cout<<"Enter the ticket price in economy class: "<<endl;
    cin>>economyPrice;
    cout<<"Enter the ticket price in business class: "<<endl;
    cin>>businessPrice;
    cout<<"Enter the price of ticket in first class: "<<endl;
    cin>>firstPrice;
    flights[flightCount].setDate(tdate);
    flights[flightCount].setTotalSeats(noOfSeats);
    flights[flightCount].setAvailableSeats(noOfSeats);
    flights[flightCount].setTotalBusinessClass(totalBusinessClass);
    flights[flightCount].setAvailableBusinessClass(totalBusinessClass);
    flights[flightCount].setTotalEconomyClass(totalEconomyClass);
    flights[flightCount].setAvailableEconomyClass(totalEconomyClass);
    flights[flightCount].setTotalFirstClass(totalFirstClass);
    flights[flightCount].setAvailableFirstClass(totalFirstClass);
    flights[flightCount].setFlightNo(flightNo);
    flights[flightCount].setCompanyName(company);
    flights[flightCount].setTiming(time);
    flights[flightCount].setBusinessClassPrice(businessPrice);
    flights[flightCount].setEconomyClassPrice(economyPrice);
    flights[flightCount].setFirstClassPrice(firstPrice);

    fstream file;
    file.open("flight.txt",ios::binary|ios::app);
    file.write((char*)(&flights[flightCount]),sizeof(flights[flightCount]));
    flightCount++;
    file.close();
}

void FlightDetails::deleteFlight(char source[],char des[],FlightDetails temp[],int& size1)
{
    int i=0;
    int length=strlen(source)>strlen(des)?strlen(source):strlen(des);

    while(i<length)
    {
        source[i]=tolower(source[i]);
        des[i]=tolower(des[i]);
        i++;
    }
    i=0;
    fstream file1;
    file1.open("flight.txt",ios::binary|ios::out);
    for(i=0; i<flightCount; i++)
    {
        if((strcmp(flights[i].getSource(),source)==0) && (strcmp(flights[i].getDestination(),des)==0))
        {
            cout<<"Flight Deleted"<<endl;
            continue;
        }
        else
        {
            file1.write((char*)(&flights[i]),sizeof(flights[i]));
        }
    }
    flightCount--;
    file1.close();
}

void FlightDetails::passengerDisplay(FlightDetails& obj)
{
    struct date temp=obj.getDate();
    cout<<"FLIGHT NUMBER        :  "<<obj.getFlightNo()<<endl;
    cout<<"COMPANY NAME         : "<<obj.getCompanyName()<<endl;
    cout<<"DATE                 : "<<temp.day<<'/'<<temp.month<<'/'<<temp.year<<endl;
    cout<<"TIMING               : "<<obj.getTiming()<<endl;
}

void FlightDetails::updateAvailableSeats(int classChoice,int bookedSeats,char source[],char destination[],char flightNum[])
{

    for(int i=0;i<flightCount;i++)
    {
        if((strcmp(flights[i].getSource(),source)== 0) && (strcmp(flights[i].getDestination(),destination)==0) && (strcmp(flights[i].getFlightNo(),flightNum)==0))
        {
            flights[i].passengerDisplay(flights[i]);
            if(classChoice==1)
            {
                int economyClassSeats=flights[i].getAvailableEconomyClass();
                economyClassSeats=economyClassSeats-bookedSeats;
                flights[i].setAvailableEconomyClass(economyClassSeats);
                economyClassSeats=flights[i].getAvailableSeats();
                economyClassSeats=economyClassSeats-bookedSeats;
                flights[i].setAvailableSeats(economyClassSeats);
            }
            else if(classChoice==2)
            {
                int businessClassSeats=flights[i].getAvailableBusinessClass();
                businessClassSeats=businessClassSeats-bookedSeats;
                flights[i].setAvailableBusinessClass(businessClassSeats);
                businessClassSeats=flights[i].getAvailableSeats();
                businessClassSeats=businessClassSeats-bookedSeats;
                flights[i].setAvailableSeats(businessClassSeats);
            }
            else if(classChoice==3)
            {
                int firstClassSeats=flights[i].getAvailableFirstClass();
                firstClassSeats=firstClassSeats-bookedSeats;
                flights[i].setAvailableFirstClass(firstClassSeats);
                firstClassSeats=flights[i].getAvailableSeats();
                firstClassSeats=firstClassSeats-bookedSeats;
                flights[i].setAvailableSeats(firstClassSeats);
            }
            break;
        }
    }

    fstream file;
    file.open("flight.txt",ios::binary|ios::out);

    for(int i=0;i<flightCount;i++)
    {
        file.write((char*)(&flights[i]),sizeof(flights[i]));
    }
    file.close();
}

void FlightDetails::flightDisplay(FlightDetails& obj)
{
    struct date temp=obj.getDate();
    cout<<setw(10)<<obj.getSource()<<setw(15)<<obj.getDestination()<<setw(10)<<setw(2)<<temp.day<<'/'<<setw(2)<<temp.month<<'/'<<setw(4)<<temp.year<<setw(10)<<obj.getTiming()<<setw(10)<<obj.getTotalSeats()<<setw(10)<<obj.getAvailableSeats()<<endl;
}

void FlightDetails::display(FlightDetails obj[],int& size1)
{
    int i=0;
    for(i=0;i<flightCount-1;i++)
    {
        char temp1[50];
        strcpy(temp1,flights[i].getSource());
        for(int j=0;j<flightCount;j++)
        {
            char temp2[50];
            strcpy(temp2,flights[j].getSource());

            if(strcmp(temp1,temp2)<0)
            {
                FlightDetails temp;
                temp=flights[i];
                flights[i]=flights[j];
                flights[j]=temp;
            }
        }
    }

    for(i=0;i<flightCount;i++)
    {
        cout<<flights[i];
    }
}


void checkDate(struct date& n1)
{
    int month=0,day=0,year=0;
    int arr[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    if(n1.month<=0 || n1.month>12)
    {
        cout<<"Enter the month: "<<endl;
        cin>>month;
        n1.month=month;
        checkDate(n1);
    }

    if(((year%4==0)&&(year%100!=0)) || (year%400==0))
    {
        arr[1]=29;
    }

    if(arr[n1.month-1]<n1.day || n1.day<=0)
    {
        cout<<"Enter the day: "<<endl;
        cin>>day;
        n1.day=day;
        checkDate(n1);
    }

    if(n1.year<2024)
    {
        cout<<"Enter the year: "<<endl;
        cin>>year;
        n1.year=year;
        checkDate(n1);
    }
}
/*
int main()
{
    FlightDetails temp;
    BookingDetails temp1;
    char source[50];
    char destination[50];
    int n=6,choice=1,size1=0,i=0;

    fstream file;
    file.open("flight.txt",ios::binary|ios::in);
    while(file.read((char*)(&flights[flightCount]),sizeof(flights[flightCount])))
    {
        cout<<flights[flightCount];
        flightCount++;
    }
    file.close();

    while(choice!=0)
    {
        cout<<"Press 1 to add flight in the register"<<endl;
        cout<<"Press 2 to delete flight"<<endl;
        cout<<"Press 3 to display"<<endl;
        cout<<"Press 0 to exit"<<endl;
        cin>>choice;
        cin.ignore(1,'\n');
        switch(choice)
        {
        case 1:
            {
            cout<<"Enter the source: "<<endl;
            cin.getline(source,50);
            cout<<"Enter the destination: "<<endl;
            cin.getline(destination,50);
            temp.addFlight(source,destination,flights,size1);
            break;
            }
        case 2:
            {
            cout<<"Enter the source: "<<endl;
            cin.getline(source,50);
            cout<<"Enter the destination: "<<endl;
            cin.getline(destination,50);
            temp.deleteFlight(source,destination,flights,size1);
            break;
            }
        case 3:
            {
            temp.display(flights,size1);
            break;
            }
        case 4:
            {
            cout<<"Enter the source: "<<endl;
            cin.getline(source,50);
            cout<<"Enter the destination: "<<endl;
            cin.getline(destination,50);
            n=temp.searching(source,destination,temp);
            cout<<n<<endl;
            break;
            }
        case 5:
            {
            cout<<"Enter the source: "<<endl;
            cin.getline(source,50);
            cout<<"Enter the destination: "<<endl;
            cin.getline(destination,50);
            temp1.bookingTicket(source,destination);
            break;
            }
        case 6:
            {
            temp.flightDisplay(flights[1]);
            break;
            }
        case 7:
            {
            int passengerNo=0;
            cout<<"Enter the passenger Number to cancellation of ticket: "<<endl;
            cin>>passengerNo;
            temp1.cancellation(passengerNo);
            break;
            }
        case 8:
            {
            int passengerNo=0;
            cout<<"Enter the passenger Number to display ticket: "<<endl;
            cin>>passengerNo;
            temp1.ticketDisplay(passengerNo);
            break;
            }
        case 9:
            {
                temp1.totalDisplay();
                break;
            }
        }
    }
    return 0;
}*/
