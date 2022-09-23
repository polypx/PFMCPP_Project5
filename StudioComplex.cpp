#include <iostream>
#include "StudioComplex.h"

StudioComplex::StudioComplex() 
{
    std::cout << "Studio Complex being constructed." << std::endl; 
}    

StudioComplex::~StudioComplex() 
{
    std::cout << "Studio Complex being deconstructed." << std::endl; 
    placeAdvertisement("ADVERTISEMENT: STUDIO FOR SALE!!!!");
}    

int StudioComplex::bookSession(const ControlRoom& controlRoom, const LiveRoom& liveRoom, int hours) const
{
    std::cout <<  "Booking " << controlRoom.name << " with " << liveRoom.name << " for " << hours << " hours" << std::endl; 
    return hours;
}

int StudioComplex::prepareInvoice(const ControlRoom& controlRoom, const LiveRoom& liveRoom, int hours, int rate) const
{
    int cost = hours * rate;
    std::cout << controlRoom.name << " with " << liveRoom.name << " fee is " << cost << " dollars" << std::endl; 
    return cost;
}

void StudioComplex::placeAdvertisement(std::string text) const
{
    std::cout << text << std::endl; 
}
