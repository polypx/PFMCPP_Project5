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

    void setNames(const std::string a, const std::string b, const std::string c, const std::string d, const std::string e);
    int setPopulations(const int a, int b, const int c, const int d, const int e);

    JUCE_LEAK_DETECTOR(LargestFiveCities)
};
