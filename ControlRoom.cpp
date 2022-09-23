#include <iostream>
#include "ControlRoom.h"

ControlRoom::ControlRoom()
: length(15), width(9), height(2), numberSeats(3), studioPowerState(false), name("Control Room A"), monitorBrand("ATC")
{
    std::cout << "ControlRoom being constructed." << std::endl;
}

ControlRoom::~ControlRoom()
{
    std::cout << "ControlRoom being deconstructed." << std::endl;
}    

ControlRoom::Computer::Computer() : powerState(true)
{
    std::cout << "Computer being constructed." << std::endl;
}

ControlRoom::Computer::~Computer() 
{
    std::cout << "Computer being deconstructed." << std::endl;
}

void ControlRoom::aboutControlRoom() const
{
    std::cout << "This control room has " << this->numberSeats << " seats." << std::endl;
}

int ControlRoom::hoursInBudget(int engineerRate, int studioRate, int budget) const
{
    int hours = 0;
    int cost = 0;
    while (cost <= budget)
    {
        ++hours;
        cost = (hours * engineerRate) + (hours * studioRate);
    } 
    std::cout << "You have " << hours << " hours in your budget." << std::endl;
    return hours;
} 


void ControlRoom::seatEngineer(std::string engineerName) const
{
    std::cout << "Today we're enjoying the mixing skills of " << engineerName << std::endl;      
}

bool ControlRoom::switchStudioPower()
{
    studioPowerState = !studioPowerState;
    std::cout << "Studio power is " << (studioPowerState ? "on" : "off") << std::endl;       
    return studioPowerState;
}

int ControlRoom::Computer::hoursTillComputerCrash(bool runningProTools)
{
    int hours = 0;
    float heat = 1.1f;
    float numberOfPlugins = 1.f;
    float willCrash = 0.3f;
    while(willCrash < 1.0f )
    {
        willCrash = willCrash * heat * numberOfPlugins;
        numberOfPlugins = numberOfPlugins * 1.2f;
        
        if (runningProTools == true)
        {
            heat = heat * 1.15f;
        }
        else
        {
            heat = heat * 1.07f;
        }    

        ++hours;
    } 
    std::cout << "Computer will crash in " << hours << " hours." << std::endl;
    return hours;
}

void ControlRoom::Computer::aboutComputer() const
{
    std::cout << "This computer is made by " << this->brand << std::endl;
}


bool ControlRoom::Computer::switchOnOff()
{
    powerState = !powerState;
    std::cout << "Computer is " << (powerState ? "on" : "off") << std::endl;  
    return powerState;
}

std::string ControlRoom::Computer::runSoftware(std::string programName) const
{
    return programName;
}

