#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"
#include "City.h"

struct LargestFiveCities
{
    LargestFiveCities();
    ~LargestFiveCities();

    City cityA;
    City cityB;
    City cityC;
    City cityD;
    City cityE;

    void setNames(std::string a, std::string b, std::string c, std::string d, std::string e);
    int setPopulations(int a, int b, int c, int d, int e);

    JUCE_LEAK_DETECTOR(LargestFiveCities)
};
