/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
Additionally, you can mark class member functions as 'const'
If you do this, you are promising that the member function will not modify any member variables.

Mark every member function that is not modifying any member variables as 'const'
*/
#if false
//a function where the argument is passed by const-ref
void someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
 */



#include <iostream>
#include "LeakedObjectDetector.h"

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

    void aboutCity();

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

        void aboutPolice();
    };

    JUCE_LEAK_DETECTOR(City)    
};

struct CityWrapper
{
    CityWrapper( City* ptr ) : pointerToCity( ptr ) {}
    ~CityWrapper()
    {
        delete pointerToCity;
    }
    City* pointerToCity = nullptr;
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

void City::aboutCity()
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

void City::PoliceDepartment::aboutPolice()
{
    std::cout << "The police have " << this->staff << " staff, and a chief named " << this->chief  << std::endl;
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

    void aboutControlRoom();

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

        void aboutComputer();
    };
    JUCE_LEAK_DETECTOR(ControlRoom)     
};

struct ControlRoomWrapper
{
    ControlRoomWrapper( ControlRoom* ptr ) : pointerToControlRoom( ptr ) {}
    ~ControlRoomWrapper()
    {
        delete pointerToControlRoom;
    }
    ControlRoom* pointerToControlRoom = nullptr;
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

void ControlRoom::aboutControlRoom()
{
    std::cout << "This control room has " << this->numberSeats << " seats." << std::endl;
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

void ControlRoom::Computer::aboutComputer()
{
    std::cout << "This computer is made by " << this->brand << std::endl;
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

    void aboutLiveRoom();

    struct Musician
    {
        Musician();                               
        ~Musician();   

        std::string name, mainInstrument;
        int yearsExperience, hourlyRate;

        void aboutMusician();
        void callMusician();
        bool createContract();
        int totalHoursUnpaid(); 
    };

    
    void seatMusician(Musician musicianName, std::string thisName);
    bool switchLights(); 
    int calculateMusicianFee(int hours, bool receivesPublishingPercentage);

    JUCE_LEAK_DETECTOR(LiveRoom)   
};

struct LiveRoomWrapper
{
    LiveRoomWrapper( LiveRoom* ptr ) : pointerToLiveRoom( ptr ) {}
    ~LiveRoomWrapper()
    {
        delete pointerToLiveRoom;
    }
    LiveRoom* pointerToLiveRoom = nullptr;
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

void LiveRoom::aboutLiveRoom()
{
    std::cout << "This live room is called " << this->name << std::endl;
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

void LiveRoom::Musician::aboutMusician()
{
    std::cout << "This musician is named " << this->name << std::endl;
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

    JUCE_LEAK_DETECTOR(StudioComplex)  
};

struct StudioComplexWrapper
{
    StudioComplexWrapper( StudioComplex* ptr ) : pointerToStudioComplex( ptr ) {}
    ~StudioComplexWrapper()
    {
        delete pointerToStudioComplex;
    }
    StudioComplex* pointerToStudioComplex = nullptr;
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

    JUCE_LEAK_DETECTOR(StudioComplex)
};

struct LargestFiveCitiesWrapper
{
    LargestFiveCitiesWrapper( LargestFiveCities* ptr ) : pointerToLargestFiveCities( ptr ) {}
    ~LargestFiveCitiesWrapper()
    {
        delete pointerToLargestFiveCities;
    }
    LargestFiveCities* pointerToLargestFiveCities = nullptr;
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
    CityWrapper toronto( new City() );
    toronto.pointerToCity->expand();
    toronto.pointerToCity->createLaw();
    toronto.pointerToCity->name = "Toronto";

    City::PoliceDepartment torontoPoliceDepartment;
    torontoPoliceDepartment.getConvictionRate(1841.f, 1123.f);
    torontoPoliceDepartment.trainRookies(7, 3);

    std::cout << "The city named " << toronto.pointerToCity->name << " has a population of " << toronto.pointerToCity->population << std::endl;
    toronto.pointerToCity->aboutCity();
    std::cout << "The police have " << torontoPoliceDepartment.staff << " staff, and a chief named " << torontoPoliceDepartment.chief  << std::endl;
    torontoPoliceDepartment.aboutPolice();

    ControlRoomWrapper factory(new ControlRoom() );
    ControlRoom::Computer mainMacintosh; 
    factory.pointerToControlRoom->hoursInBudget(75, 60, 5000);
    mainMacintosh.hoursTillComputerCrash(true);  
    std::cout << "This control room has " << factory.pointerToControlRoom->numberSeats << " seats." << std::endl;
    factory.pointerToControlRoom->aboutControlRoom();
    std::cout << "This computer is made by " << mainMacintosh.brand << std::endl;
    mainMacintosh.aboutComputer();

    LiveRoomWrapper studioA(new LiveRoom() );
    LiveRoom::Musician tony;  
    studioA.pointerToLiveRoom->seatMusician(tony, "Tony");
    studioA.pointerToLiveRoom->calculateMusicianFee(31, false);
    studioA.pointerToLiveRoom->switchLights();
    std::cout << "This live room is called " << studioA.pointerToLiveRoom->name << std::endl;
    studioA.pointerToLiveRoom->aboutLiveRoom();

    StudioComplexWrapper olympic( new StudioComplex() );
    olympic.pointerToStudioComplex->controlRoomB.name = "Control Room B";
    olympic.pointerToStudioComplex->liveRoomB.name = "Live Room B";
    olympic.pointerToStudioComplex->bookSession(olympic.pointerToStudioComplex->controlRoomA, olympic.pointerToStudioComplex->liveRoomB, 10);
    olympic.pointerToStudioComplex->prepareInvoice(olympic.pointerToStudioComplex->controlRoomB, olympic.pointerToStudioComplex->liveRoomA, 10, 76);

    LargestFiveCitiesWrapper largestCanadianCities( new LargestFiveCities() ) ;
    largestCanadianCities.pointerToLargestFiveCities->setNames("Vancouver", "Toronto", "Montreal", "Calgary", "Ottawa");
    largestCanadianCities.pointerToLargestFiveCities->setPopulations(2632000, 6313000, 4291732, 1484806, 1488307);

    std::cout << "good to go!" << std::endl;
}
