#pragma once
#include "LeakedObjectDetector.h"


struct LiveRoom
{
    LiveRoom();                               
    ~LiveRoom();    

    int length = 26;
    int width = 19;
    int height = 4;
    std::string wallMaterial = "cloth";
    std::string floorMaterial = "wood";
    bool lightsCurrentState = false; 
    std::string name = "Studio A";

    void aboutLiveRoom() const;

    struct Musician
    {
        Musician();                               
        ~Musician();   

        std::string name, mainInstrument;
        int yearsExperience, hourlyRate;

        void aboutMusician() const;
        void callMusician() const;
        bool createContract() const;
        int totalHoursUnpaid() const; 
    };

    
    void seatMusician(const Musician musicianName, const std::string thisName) const;
    bool switchLights(); 
    int calculateMusicianFee(const int hours, const bool receivesPublishingPercentage) const;

    JUCE_LEAK_DETECTOR(LiveRoom)   
};
