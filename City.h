#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"

struct City
{
    City();
    ~City();

    std::string name, country;
    std::string newLawName = "Friday's Off";
    int population = 5000000;
    float latitude = 43.6532f;    
    float longitude = -79.3470f;  

    void expand(float expansionRate = 1.1f);
    std::string createLaw() const; 
    int updatePopulation(int immigrantsYear, int emigrantsYear, int birthsYear, int deathsYear, int years);  

    void aboutCity() const;

    struct PoliceDepartment
    {
        PoliceDepartment();
        ~PoliceDepartment();

        int staff, budgetMillions, salary;
        float crimeRate = 0.f;
        std::string chief = "unnamedPoliceChief";

        float getConvictionRate(float arrests, float convictions) const;
        void trainRookies(int rookies, int monthsTraining) const;
        int checkStaffCost(int numberStaff, int monthlySalary) const;

        void aboutPolice() const;
    };

    JUCE_LEAK_DETECTOR(City)    
};


