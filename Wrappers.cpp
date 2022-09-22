#include "Wrappers.h"

CityWrapper::CityWrapper( City* ptr ) : pointerToCity( ptr ) {} 
CityWrapper::~CityWrapper()
{
    delete pointerToCity;
}

ControlRoomWrapper::ControlRoomWrapper( ControlRoom* ptr ) : pointerToControlRoom( ptr ) {}
ControlRoomWrapper::~ControlRoomWrapper()
{
    delete pointerToControlRoom;
}

LiveRoomWrapper::LiveRoomWrapper( LiveRoom* ptr ) : pointerToLiveRoom( ptr ) {}
LiveRoomWrapper::~LiveRoomWrapper()
{
    delete pointerToLiveRoom;
}

StudioComplexWrapper::StudioComplexWrapper( StudioComplex* ptr ) : pointerToStudioComplex( ptr ) {}
StudioComplexWrapper::~StudioComplexWrapper()
{
    delete pointerToStudioComplex;
}

LargestFiveCitiesWrapper::LargestFiveCitiesWrapper( LargestFiveCities* ptr ) : pointerToLargestFiveCities( ptr ) {}
LargestFiveCitiesWrapper::~LargestFiveCitiesWrapper()
{
    delete pointerToLargestFiveCities;
}
