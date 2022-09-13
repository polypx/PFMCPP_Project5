/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

NOTE: there are 2 sets of instructions:
       One for if you completed project 3
       One for if you skipped project 3.

 Destructors

===============================================================     
 If you completed Project 3:
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.
===============================================================
If you skipped Project 3:
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
===============================================================

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

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
    std::cout << convictions / arrests << " is the conviction rate." << std::endl;
    return convictions / arrests;
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

    int length, width, height, numberSeats;
    bool studioPowerState; 
    std::string monitorBrand;
    
    int  hoursInBudget(int engineerRate, int studioRate, int budget);
    void seatEngineer(std::string engineerName);
    bool switchStudioPower(); // returns state of studio power

    struct Computer
    {
        Computer();
    
        std::string brand = "Apple";                // in CLASS initialisation
        int CPUspeed = 3200;  
        int RAMsize = 64;
        int age = 2;
        int price = 2400;
        bool powerState = false; 
    
        bool switchOnOff(); // returns current power state
        std::string runSoftware(std::string applicationName); // return app name
        int hoursTillComputerCrash(bool runningProTools);
    };
        
};

ControlRoom::ControlRoom()
: length(15), width(9), height(2), numberSeats(3), studioPowerState(false), monitorBrand("ATC")
{
    std::cout << "ControlRoom being constructed." << std::endl;
}

int ControlRoom::hoursInBudget(int engineerRate, int studioRate, int budget)
{
    int hours = 0;
    int cost = 0;
    while (cost <= budget)
    {
        ++hours;
        cost = hours*engineerRate + hours*studioRate;
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
    if (studioPowerState)
    {
        std::cout << "Studio power is ON. "  << std::endl;       
    }
    else
    {
        std::cout << "Studio power is OFF. "  << std::endl; 
    }    
    return studioPowerState;
}

ControlRoom::Computer::Computer()
{
    std::cout << "Computer being constructed." << std::endl;
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
    if (powerState)
    {
        std::cout << "The computer is currently on."  << std::endl; 
    } 
    else
    {
        std::cout << "The computer is currently off."  << std::endl; 
    }    
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
    LiveRoom();                                // in  CLASS initialisation 

    int length = 26;
    int width = 19;
    int height = 4;
    std::string wallMaterial = "cloth";
    std::string floorMaterial = "wood";
    bool lightsCurrentState = false; 
    std::string studioName = "Studio A";

    struct Musician
    {
        std::string name, mainInstrument;
        int yearsExperience, hourlyRate;

        Musician() : name("John"), mainInstrument("Piano"), yearsExperience(10), hourlyRate(75) {}

        void callMusician();
        bool createContract(); // returns contract created or not
        int totalHoursUnpaid(); // returns total hours not yet paid
    };

    struct Equipment
    {
        std::string instrument1, instrument2, instrument3;

        Equipment() : instrument1("Piano"), instrument2("Guitar"), instrument3("Drums")  {}

        void tunePiano(); 
        bool switchHammond(); 
        bool enableSnaresOnSnareDrum(); 

    };

    void seatMusician(Musician musicianName, std::string thisName);
    void placeEquipment(Equipment steinwayPiano);
    bool switchLights(); 
    int calculateMusicianFee(int hours, bool receivesPublishingPercentage);
};

LiveRoom::LiveRoom()
{
    std::cout << "LiveRoom being constructed." << std::endl;
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


void LiveRoom::placeEquipment(Equipment instrumentType)
{
    std::cout << "We have taken delivery of a " << instrumentType.instrument1  << std::endl;     
}

bool LiveRoom::switchLights()
{
    lightsCurrentState = !lightsCurrentState;
    if (lightsCurrentState)
    {
        std::cout << "The lights are currently on."  << std::endl; 
    } 
    else
    {
        std::cout << "The lights are currently off."  << std::endl; 
    }
    
    return lightsCurrentState;
}


/*
 new UDT 4:
 with 2 member functions
 */

/*
 new UDT 5:
 with 2 member functions
 */

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
    std::cout << "This population will be " <<  toronto.updatePopulation(4000, 1500, 18000, 17000, 5)   << " in 5 years." << std::endl;
    torontoPoliceDepartment.getConvictionRate(1841.f, 1123.f);
    torontoPoliceDepartment.trainRookies(7, 3);

    
    std::cout << "good to go!" << std::endl;
}
