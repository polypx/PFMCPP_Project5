#include <iostream>
#include "LiveRoom.h"

LiveRoom::LiveRoom()
{
    std::cout << "LiveRoom being constructed." << std::endl;
}

LiveRoom::~LiveRoom()
{
    std::cout << "LiveRoom being deconstructed." << std::endl;
}

LiveRoom::Musician::Musician() : name("John"), mainInstrument("Piano"), yearsExperience(10), hourlyRate(75)
{
    std::cout << "Musician being constructed." << std::endl;
}

LiveRoom::Musician::~Musician() 
{
    std::cout << "Musician being deconstructed." << std::endl;
}

void LiveRoom::aboutLiveRoom() const
{
    std::cout << "This live room is called " << this->name << std::endl;
}

int LiveRoom::calculateMusicianFee(int hours, bool receivesPublishingPercentage) const
{
    int musicianFee = 0;    
    for (int i = 0; i <= hours; ++i)
    {
        if(receivesPublishingPercentage == true)
        {
            musicianFee += 45;     // no overtime fee 
        }
        else
        {
            musicianFee += 115;
            if(i % 10 == 0)
            {
                musicianFee += 30; // overtime fee
            }                
        }    
    }
    std::cout << "He is charging $" << musicianFee << " for this session." << std::endl;   
    return musicianFee;
}

void LiveRoom::seatMusician(Musician musicianName, std::string thisName) const
{
    musicianName.name = thisName;
    std::cout << "Today we're enjoying the dulcet tones of " << musicianName.name  << std::endl;    
}


bool LiveRoom::switchLights()
{
    lightsCurrentState = !lightsCurrentState;
    std::cout << "The lights are currently " << (lightsCurrentState ? "on." : "off.") << std::endl; 
    return lightsCurrentState;
}

void LiveRoom::Musician::aboutMusician() const
{
    std::cout << "This musician is named " << this->name << std::endl;
}
