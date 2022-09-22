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

    void expand(const float expansionRate = 1.1f);
    std::string createLaw() const; 
    int updatePopulation(const int immigrantsYear, const int emigrantsYear, const int birthsYear, const int deathsYear, const int years);  

    void aboutCity() const;

    struct PoliceDepartment
    {
        PoliceDepartment();
        ~PoliceDepartment();

        int staff, budgetMillions, salary;
        float crimeRate = 0.f;
        std::string chief = "unnamedPoliceChief";

        float getConvictionRate(const float arrests, const float convictions) const;
        void trainRookies(const int rookies, const int monthsTraining) const;
        int checkStaffCost(const int numberStaff, const int monthlySalary) const;

        void aboutPolice() const;
    };

    JUCE_LEAK_DETECTOR(City)    
};


