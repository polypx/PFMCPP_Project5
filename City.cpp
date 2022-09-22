#include <iostream>
#include "City.h"

City::City() : name("Montreal"), country("Canada"), population(5000000)
{
    std::cout << "City being constructed." << std::endl;
}

City::~City()
{
    std::cout << "City being deconstructed." << std::endl;
}


City::PoliceDepartment::PoliceDepartment() : staff(4500), budgetMillions(500), salary(85000)
{
    std::cout << "PoliceDepartment being constructed." << std::endl;
}

City::PoliceDepartment::~PoliceDepartment() 
{
    std::cout << "PoliceDepartment being deconstructed." << std::endl;
}

void City::aboutCity() const
{
    std::cout << "The city named " << this->name << " has a population of " << this->population << std::endl;
}

void City::expand(float expansionRate) 
{
    if(expansionRate < 0.f)
    {
        std::cout << "we're shrinking!" << std::endl;    
    } 
}

std::string City::createLaw()
{
  return newLawName;  
}

int City::updatePopulation(int immigrantsYear, int emigrantsYear, int birthsYear, int deathsYear, int years)
{
    for(int i = 0; i <= years; ++i)
    {
        population = population + immigrantsYear - emigrantsYear + birthsYear - deathsYear;
    }    
    return population;
}

float City::PoliceDepartment::getConvictionRate(float arrests, float convictions) const
{
    float rate = convictions / arrests;
    std::cout << rate << " is the conviction rate." << std::endl;
    return rate;
}

void City::PoliceDepartment::trainRookies(int rookies, int monthsTraining) const
{
    for (int i = 1; i <= monthsTraining; ++i)
    {
        std::cout << i * rookies << " combined months of training costs." << std::endl;
    }    
}

void City::PoliceDepartment::aboutPolice() const
{
    std::cout << "The police have " << this->staff << " staff, and a chief named " << this->chief  << std::endl;
}


