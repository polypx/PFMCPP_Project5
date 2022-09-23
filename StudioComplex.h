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

    int bookSession(const ControlRoom& controlRoom, const LiveRoom& liveRoom, const int hours) const;
    int prepareInvoice(const ControlRoom& controlRoom, const LiveRoom& liveRoom, const int hours, int rate) const;
    void placeAdvertisement(const std::string text) const; 

    JUCE_LEAK_DETECTOR(StudioComplex)  
};

