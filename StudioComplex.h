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

    int bookSession(const ControlRoom& controlRoom, const LiveRoom& liveRoom, int hours) const;
    int prepareInvoice(const ControlRoom& controlRoom, const LiveRoom& liveRoom, int hours, int rate) const;
    void placeAdvertisement(std::string text) const; 

    JUCE_LEAK_DETECTOR(StudioComplex)  
};

