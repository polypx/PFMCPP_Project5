/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp, which goes along with instruction 5): 
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
        Chances are extremely high that you implemented your 
        wrapper class functions in-class, because that is what 
        everyone does after watching the video where I implemented 
        them in-class.
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.

 7) When you add the #include statements for your refactored source files into main.cpp: 
        '#include "Wrappers.h"' should be the first file that you include after LeakedObjectDetector.h
 
 8) Go through every cpp file and header file. check all function implementations for the following:
        Can this function argument be declared as 'const'? 
        Can this function be declared as 'const'?
        You learned about 'const' function arguments and 'const' functions in Project 5 Part 3
        As a refresher:
            If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
            Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
            Additionally, you can mark class member functions as 'const'
            If you do this, you are promising that the member function will not modify any member variables.

        Mark every member function that is not modifying any member variables as 'const'
        Mark every function parameter that is not modified inside the function as 'const'
*/
#if false
//a function where the argument is passed by const-ref.
void Foo::someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 9) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.
 */

#include "LeakedObjectDetector.h"
#include "Wrappers.h"
#include "City.h"
#include "ControlRoom.h"
#include "LiveRoom.h"
#include "StudioComplex.h"
#include "LargestFiveCities.h"
#include <iostream>



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
