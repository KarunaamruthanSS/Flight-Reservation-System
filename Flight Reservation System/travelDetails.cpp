#include<iostream>
#include<cstring>
#include<string.h>
#include"travelDetails.h"
using namespace std;

TravelDetails::TravelDetails()
{
    strcpy(source," ");
    strcpy(destination," ");
    strcpy(flightNo," ");
}

TravelDetails::TravelDetails(char srce[],char des[],char flightNum[])
{
    strcpy(source,srce);
    strcpy(destination,des);
    strcpy(flightNo,flightNum);
}

TravelDetails::TravelDetails(const TravelDetails& obj)
{
    strcpy(source,obj.source);
    strcpy(destination,obj.destination);
    strcpy(flightNo,obj.flightNo);
}

void TravelDetails::setSource(char tsource[])
{
    strcpy(this->source,tsource);
}

void TravelDetails::setDestination(char tdestination[])
{
    strcpy(this->destination,tdestination);
}

const char* TravelDetails::getDestination() const
{
    return this->destination;
}

const char* TravelDetails::getSource() const
{
    return this->source;
}

void TravelDetails::setFlightNo(char tflightNo[])
{
    strcpy(flightNo,tflightNo);
}

const char* TravelDetails::getFlightNo()
{
    return this->flightNo;
}
