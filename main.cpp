/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via the 'this' keyword and arrow (->) operator and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 Instructions:
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.

 2) Do the following for EVERY std::cout statement in main() that uses the UDT member variables and functions:
    a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
    b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
    c) call that member function AFTER your std::cout statement in main.
    NOTE: if your member functions being called in main() use std::cout statements, you don't need to create duplicates of these functions.  you only need to create member functions for the std::cout statements that exist in main().
        
 3) you should see 2 (almost) identical messages in the program output for each member function you add:
    one for the std::cout line, and one for the member function's output
 
 4) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo();
        ~MyFoo();
        
        void printDetailedMemberInfo();
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };

    MyFoo::MyFoo() { std::cout << "creating MyFoo" << std::endl; }
    MyFoo::~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
	// 2a) the member function whose function body is almost identical to the std::cout statement in main.
    //Remember to NAME FUNCTIONS WHAT THEY DO.
    void MyFoo::printDetailedMemberInfo() //function name contains a verb!!!
    { 
        // 2b) explicitly using 'this' inside this member function.
        std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
    }  
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.printDetailedMemberInfo();
        return 0;
    }
}

/*

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.
*/

#include <iostream>

/*
 copied UDT 1:
 */

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
    std::string createLaw(); 
    int updatePopulation(int immigrantsYear, int emigrantsYear, int birthsYear, int deathsYear, int years);  

    struct PoliceDepartment
    {
        PoliceDepartment();
        ~PoliceDepartment();

        int staff, budgetMillions, salary;
        float crimeRate = 0.f;
        std::string chief = "unnamedPoliceChief";

        float getConvictionRate(float arrests, float convictions);
        void trainRookies(int rookies, int monthsTraining);
        int checkStaffCost(int numberStaff, int monthlySalary);
    };
};

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

float City::PoliceDepartment::getConvictionRate(float arrests, float convictions)
{
    float rate = convictions / arrests;
    std::cout << rate << " is the conviction rate." << std::endl;
    return rate;
}

void City::PoliceDepartment::trainRookies(int rookies, int monthsTraining)
{
    for (int i = 1; i <= monthsTraining; ++i)
    {
        std::cout << i * rookies << " combined months of training costs." << std::endl;
    }    
}


/*
 copied UDT 2:
 */

struct ControlRoom
{
    ControlRoom();
    ~ControlRoom();

    int length, width, height, numberSeats;
    bool studioPowerState; 
    std::string name, monitorBrand;
    
    int  hoursInBudget(int engineerRate, int studioRate, int budget);
    void seatEngineer(std::string engineerName);
    bool switchStudioPower(); 

    struct Computer
    {
        Computer();
        ~Computer();
    
        std::string brand = "Apple";                
        int CPUspeed = 3200;  
        int RAMsize = 64;
        int age = 2;
        int price = 2400;
        bool powerState = false; 
    
        bool switchOnOff(); 
        std::string runSoftware(std::string applicationName); 
        int hoursTillComputerCrash(bool runningProTools);
    };
        
};

ControlRoom::ControlRoom()
: length(15), width(9), height(2), numberSeats(3), studioPowerState(false), name("Control Room A"), monitorBrand("ATC")
{
    std::cout << "ControlRoom being constructed." << std::endl;
}

ControlRoom::~ControlRoom()
{
    std::cout << "ControlRoom being deconstructed." << std::endl;
}    

ControlRoom::Computer::Computer() : powerState(true)
{
    std::cout << "Computer being constructed." << std::endl;
}

ControlRoom::Computer::~Computer() 
{
    std::cout << "Computer being deconstructed." << std::endl;
}


int ControlRoom::hoursInBudget(int engineerRate, int studioRate, int budget)
{
    int hours = 0;
    int cost = 0;
    while (cost <= budget)
    {
        ++hours;
        cost = (hours * engineerRate) + (hours * studioRate);
    } 
    std::cout << "You have " << hours << " hours in your budget." << std::endl;
    return hours;
} 


void ControlRoom::seatEngineer(std::string engineerName)
{
    std::cout << "Today we're enjoying the mixing skills of " << engineerName << std::endl;      
}

bool ControlRoom::switchStudioPower()
{
    studioPowerState = !studioPowerState;
    std::cout << "Studio power is " << (studioPowerState ? "on" : "off") << std::endl;       
    return studioPowerState;
}

int ControlRoom::Computer::hoursTillComputerCrash(bool runningProTools)
{
    int hours = 0;
    float heat = 1.1f;
    float numberOfPlugins = 1.f;
    float willCrash = 0.3f;
    while(willCrash < 1.0f )
    {
        willCrash = willCrash * heat * numberOfPlugins;
        numberOfPlugins = numberOfPlugins * 1.2f;
        
        if (runningProTools == true)
        {
            heat = heat * 1.15f;
        }
        else
        {
            heat = heat * 1.07f;
        }    

        ++hours;
    } 
    std::cout << "Computer will crash in " << hours << " hours." << std::endl;
    return hours;
}

bool ControlRoom::Computer::switchOnOff()
{
    powerState = !powerState;
    std::cout << "Computer is " << (powerState ? "on" : "off") << std::endl;  
    return powerState;
}

std::string ControlRoom::Computer::runSoftware(std::string programName)
{
    return programName;
}

/*
 copied UDT 3:
 */


struct LiveRoom
{
    LiveRoom();                               
    ~LiveRoom();    

    int length = 26;
    int width = 19;
    int height = 4;
    std::string wallMaterial = "cloth";
    std::string floorMaterial = "wood";
    bool lightsCurrentState = false; 
    std::string name = "Studio A";

    struct Musician
    {
        Musician();                               
        ~Musician();   

        std::string name, mainInstrument;
        int yearsExperience, hourlyRate;

        void callMusician();
        bool createContract();
        int totalHoursUnpaid(); 
    };

    void seatMusician(Musician musicianName, std::string thisName);
    bool switchLights(); 
    int calculateMusicianFee(int hours, bool receivesPublishingPercentage);
};

LiveRoom::LiveRoom()
{
    std::cout << "LiveRoom being constructed." << std::endl;
}

LiveRoom::~LiveRoom()
{
    std::cout << "LiveRoom being deconstructed." << std::endl;
}

LiveRoom::Musician::Musician() : name("John"), mainInstrument("Piano"), yearsExperience(10), hourlyRate(75)
{
    std::cout << "Musician being constructed." << std::endl;
}

LiveRoom::Musician::~Musician() 
{
    std::cout << "Musician being deconstructed." << std::endl;
}

int LiveRoom::calculateMusicianFee(int hours, bool receivesPublishingPercentage)
{
    int musicianFee = 0;    
    for (int i = 0; i <= hours; ++i)
    {
        if(receivesPublishingPercentage == true)
        {
            musicianFee += 45;     // no overtime fee 
        }
        else
        {
            musicianFee += 115;
            if(i % 10 == 0)
            {
                musicianFee += 30; // overtime fee
            }                
        }    
    }
    std::cout << "He is charging $" << musicianFee << " for this session." << std::endl;   
    return musicianFee;
}

void LiveRoom::seatMusician(Musician musicianName, std::string thisName)
{
    musicianName.name = thisName;
    std::cout << "Today we're enjoying the dulcet tones of " << musicianName.name  << std::endl;    
}


bool LiveRoom::switchLights()
{
    lightsCurrentState = !lightsCurrentState;
    std::cout << "The lights are currently " << (lightsCurrentState ? "on." : "off.") << std::endl; 
    return lightsCurrentState;
}


/*
 new UDT 4:
 with 2 member functions
 */

struct StudioComplex
{
    StudioComplex();
    ~StudioComplex();

    ControlRoom controlRoomA;
    ControlRoom controlRoomB;
    LiveRoom liveRoomA;
    LiveRoom liveRoomB;

    int bookSession(ControlRoom controlRoom, LiveRoom liveRoom, int hours);
    int prepareInvoice(ControlRoom controlRoom, LiveRoom liveRoom, int hours, int rate);
    void placeAdvertisement(std::string text); 
};

StudioComplex::StudioComplex() 
{
    std::cout << "Studio Complex being constructed." << std::endl; 
}    

StudioComplex::~StudioComplex() 
{
    std::cout << "Studio Complex being deconstructed." << std::endl; 
    placeAdvertisement("ADVERTISEMENT: STUDIO FOR SALE!!!!");
}    

int StudioComplex::bookSession(ControlRoom controlRoom, LiveRoom liveRoom, int hours)
{
    std::cout <<  "Booking " << controlRoom.name << " with " << liveRoom.name << " for " << hours << " hours" << std::endl; 
    return hours;
}

int StudioComplex::prepareInvoice(ControlRoom controlRoom, LiveRoom liveRoom, int hours, int rate)
{
    int cost = hours * rate;
    std::cout << controlRoom.name << " with " << liveRoom.name << " fee is " << cost << " dollars" << std::endl; 
    return cost;
}

void StudioComplex::placeAdvertisement(std::string text)
{
    std::cout << text << std::endl; 
}

/*
 new UDT 5:
 with 2 member functions
 */

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
};

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


/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */


int main()
{
    City toronto;         
    toronto.expand();
    toronto.createLaw();
    City::PoliceDepartment torontoPoliceDepartment;
    std::cout << "The population will be " <<  toronto.updatePopulation(4000, 1500, 18000, 17000, 5)   << " in 5 years." << std::endl;
    torontoPoliceDepartment.getConvictionRate(1841.f, 1123.f);
    torontoPoliceDepartment.trainRookies(7, 3);

    ControlRoom factory;    
    ControlRoom::Computer mainMacintosh;  
    factory.hoursInBudget(75, 60, 5000);
    mainMacintosh.hoursTillComputerCrash(true);    
    
    LiveRoom studioA;    
    LiveRoom::Musician tony;  
    studioA.seatMusician(tony, "Tony");
    studioA.calculateMusicianFee(31, false);
    studioA.switchLights();
    studioA.switchLights();

    StudioComplex Olympic;
    Olympic.controlRoomB.name = "Control Room B";
    Olympic.liveRoomB.name = "Live Room B";
    Olympic.bookSession(Olympic.controlRoomA, Olympic.liveRoomB, 10);
    Olympic.prepareInvoice(Olympic.controlRoomB, Olympic.liveRoomA, 10, 76);
    
    LargestFiveCities largestCanadianCities;
    largestCanadianCities.setNames("Vancouver", "Toronto", "Montreal", "Calgary", "Ottawa");
    largestCanadianCities.setPopulations(2632000, 6313000, 4291732, 1484806, 1488307);
    
    std::cout << "good to go!" << std::endl;
}
