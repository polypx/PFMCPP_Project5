#pragma once
#include "LeakedObjectDetector.h"
#include "ControlRoom.h"
#include "LiveRoom.h"

struct StudioComplex
{
    StudioComplex();
    ~StudioComplex();

    ControlRoom controlRoomA;
    ControlRoom controlRoomB;
    LiveRoom liveRoomA;
    LiveRoom liveRoomB;

    int bookSession(ControlRoom controlRoom, LiveRoom liveRoom, int hours) const;
    int prepareInvoice(ControlRoom controlRoom, LiveRoom liveRoom, int hours, int rate) const;
    void placeAdvertisement(std::string text) const; 

    JUCE_LEAK_DETECTOR(StudioComplex)  
};

