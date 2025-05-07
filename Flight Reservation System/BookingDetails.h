#ifndef INCLUDE_BOOKINGDETAILS_H
#define INCLUDE_BOOKINGDETAILS_H
#include"travelDetails.h"
using namespace std;

class BookingDetails:public TravelDetails
{
    char passengerName[50];
    char phoneNo[50];
    char state[50];
    char city[50];
    char street[50];
    int doorNo;
    int passengerNo;
    int seatCount;
    int classType;

public:
    BookingDetails();
    BookingDetails(char[],char[],char[],char[],char[],char[],char[],char[],int,int,int,int);
    BookingDetails(const BookingDetails&);

    void setPassengerName(char[]);
    void setPassengerNo(int);
    void setPhoneNo(char[]);
    void setState(char[]);
    void setCity(char[]);
    void setStreet(char[]);
    void setDoorNo(int);
    void setSeatCount(int);
    void setClassType(int);

    int getPassengerNo() const;
    int getDoorNo() const;
    int getSeatCount() const;
    int getClassType() const;
    const char* getPassengerName() const;
    const char* getPhoneNo() const;
    const char* getState() const;
    const char* getStreet() const;
    const char* getCity() const;

    void cancellation(int);
    void display(BookingDetails&);
    void totalDisplay();
    void bookingTicket(char[],char[]);
    void passengerDetails();
    void ticketDisplay(int);
    bool operator==(BookingDetails&);
};

#endif // INCLUDE_BOOKINGDETAILS_H
