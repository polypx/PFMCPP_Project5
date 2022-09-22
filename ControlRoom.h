#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"

struct ControlRoom
{
    ControlRoom();
    ~ControlRoom();

    int length, width, height, numberSeats;
    bool studioPowerState; 
    std::string name, monitorBrand;
    
    int  hoursInBudget(const int engineerRate, const int studioRate, const int budget) const;
    void seatEngineer(const std::string engineerName) const;
    bool switchStudioPower(); 

    void aboutControlRoom() const;

    struct Computer
    {
        Computer();
        ~Computer();
    
        std::string brand = "Apple";                
        int CPUspeed = 3200;  
        int RAMsize = 64;
        int age = 2;
        int price = 2400;
        bool powerState = false; 
    
        bool switchOnOff(); 
        std::string runSoftware(const std::string applicationName) const; 
        int hoursTillComputerCrash(const bool runningProTools);

        void aboutComputer() const;
    };
    JUCE_LEAK_DETECTOR(ControlRoom)     
};
