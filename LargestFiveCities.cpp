#include <iostream>
#include "LargestFiveCities.h"

LargestFiveCities::LargestFiveCities() 
{
    std::cout << "LargestFiveCities being constructed." << std::endl; 
}    

LargestFiveCities::~LargestFiveCities() 
{
    std::cout << "LargestFiveCities being deconstructed." << std::endl; 
}    

void LargestFiveCities::setNames(std::string a, std::string b, std::string c, std::string d, std::string e)
{
    cityA.name = a;
    cityB.name = b;
    cityC.name = c;
    cityD.name = d;
    cityE.name = e;

    std::cout << "The largest cities are " << a << ", " << b << ", " << c << ", " << d << ", and " << e << "." << std::endl; 
}

int LargestFiveCities::setPopulations(int a, int b, int c, int d, int e)
{
    cityA.population = a;
    cityB.population = b;
    cityC.population = c;
    cityD.population = d;
    cityE.population = e;

    int sum = a + b + c + d + e; 
    std::cout << "Combined population is " << sum << std::endl; 
    return sum;
}
