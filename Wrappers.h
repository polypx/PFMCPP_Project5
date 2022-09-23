#pragma once
struct City;
struct ControlRoom;
struct LiveRoom;
struct StudioComplex;
struct LargestFiveCities;

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
