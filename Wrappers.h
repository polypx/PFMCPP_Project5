#pragma once

#include "City.h"
#include "ControlRoom.h"
#include "LiveRoom.h"
#include "StudioComplex.h"
#include "LargestFiveCities.h"

struct CityWrapper
{
    CityWrapper( City* ptr );
    ~CityWrapper();
    City* pointerToCity = nullptr;
};

struct ControlRoomWrapper
{
    ControlRoomWrapper( ControlRoom* ptr );
    ~ControlRoomWrapper();
    ControlRoom* pointerToControlRoom = nullptr;
};

struct LiveRoomWrapper
{
    LiveRoomWrapper( LiveRoom* ptr );
    ~LiveRoomWrapper();
    LiveRoom* pointerToLiveRoom = nullptr;
};

struct StudioComplexWrapper
{
    StudioComplexWrapper( StudioComplex* ptr );
    ~StudioComplexWrapper();
    StudioComplex* pointerToStudioComplex = nullptr;
};

struct LargestFiveCitiesWrapper
{
    LargestFiveCitiesWrapper( LargestFiveCities* ptr );
    ~LargestFiveCitiesWrapper();
    LargestFiveCities* pointerToLargestFiveCities = nullptr;
};
