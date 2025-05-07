#ifndef INCLUDE_FLIGHTDETAILS_H
#define INCLUDE_FLIGHTDETAILS_H
#include"travelDetails.h"
#include<cstring>
#include<iostream>
using namespace std;
struct date
{
    int year;
    int month;
    int day;
};

class FlightDetails:public TravelDetails
{
    struct date flightDate;
    double timing;
    double firstPrice;
    double economyPrice;
    double businessPrice;
    int totalSeats;
    int totalBusinessClass;
    int totalEconomyClass;
    int totalFirstClass;
    int availableBusinessClass;
    int availableEconomyClass;
    int  availableFirstClass;
    int availableSeats;
    char companyName[50];

public:

    FlightDetails();
    FlightDetails(char[],char[],char[],char[],struct date,double,double,double,double,int,int,int,int,int,int,int,int);
    FlightDetails(const FlightDetails&);
    int searching(char[],char[],FlightDetails&);
    int searchFlightNo(char[],FlightDetails&);
    void addFlight(char[],char[],FlightDetails[],int&);
    void deleteFlight(char[],char[],FlightDetails[],int&);
    void display(FlightDetails[],int&);
    void passengerDisplay(FlightDetails&);
    void updateAvailableSeats(int,int,char[],char[],char[]);
    double getTiming() const;
    double getPrice() const;
    int getAvailableSeats() const;
    int getTotalSeats() const;
    int getAvailableFirstClass() const;
    int getAvailableBusinessClass() const;
    int getAvailableEconomyClass() const;
    int getTotalFirstClass() const;
    int getTotalEconomyClass() const;
    int getTotalBusinessClass() const;
    double getFirstClassPrice() const;
    double getEconomyClassPrice() const;
    double getBusinessClassPrice() const;
    struct date getDate() const;
    const char* getCompanyName() const;
    friend std::ostream& operator<<(std::ostream&,const FlightDetails&);
    FlightDetails& operator=(FlightDetails&);
    void flightDisplay(FlightDetails&);
    void setTiming(double);
    void setPrice(double);
    void setAvailableSeats(int);
    void setTotalSeats(int);
    void setAvailableFirstClass(int);
    void setAvailableBusinessClass(int);
    void setAvailableEconomyClass(int);
    void setTotalFirstClass(int);
    void setTotalEconomyClass(int);
    void setTotalBusinessClass(int);
    void setDate(struct date);
    void setCompanyName(char[]);
    void setFirstClassPrice(double);
    void setEconomyClassPrice(double);
    void setBusinessClassPrice(double);
};

#endif // INCLUDE_FLIGHTDETAILS_H
