#ifndef INCLUDE_TRAVELDETAILS_H
#define INCLUDE_TRAVELDETAILS_H
using namespace std;
class TravelDetails
{
protected:
    char source[50];
    char destination[50];
    char flightNo[50];
public:
    TravelDetails();
    TravelDetails(char[],char[],char[]);
    TravelDetails(const TravelDetails&);
    void setSource(char[]);
    void setDestination(char[]);
    void setFlightNo(char[]);
    const char* getFlightNo();
    const char* getSource() const;
    const char* getDestination() const;
};
#endif // INCLUDE_TRAVELDETAILS_H
