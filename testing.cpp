/**
 * \file testing.cpp
 * \authors Max Maleno [mmaleno@hmc.edu]
 * \brief Testing script for the timer class
 *
 * \details Created 12/27/19, last updated 12/27/19
 */

#include <iostream>
#include <ostream>
#include <cassert>
#include <ctime>
#include "timer/timer.hpp"
#include <iomanip> // only for put_time in poop.  not needed elsewhere

using namespace std;

///////////////////////////////////////////////////////////
//  TESTS
///////////////////////////////////////////////////////////

// test template

void timer_test() {
    Timer test = Timer(1567904460);
    test.update();
    cout << test.getEventEpochTime() << endl;
    cout << test.getDays() << endl;
    cout << test.getHours() << endl;
    cout << test.getMinutes() << endl;
    cout << test.getSeconds() << endl;
    test.printEventTime();
    //assert(test.get_placeholder1() == 2);
    cout << "template_test passed!" << endl;
}

 
int poop()
{
    time_t kek = 1567904460;
    
    cout << "UTC:       " << put_time(gmtime(&kek), "%c %Z") << '\n';
    cout << "local:     " << put_time(localtime(&kek), "%c %Z") << '\n';
    return 0;
}

void crap(bool live) {
    time_t currentTimeT;
    struct tm* tmStruct;
    if(live) {
        while(1) {
            
            currentTimeT = time(nullptr);
            tmStruct = localtime(&currentTimeT);
            cout
            << tmStruct->tm_mon + 1 << " "
            << tmStruct->tm_mday << " "
            << tmStruct->tm_year + 1900 << " "
            << tmStruct->tm_hour << " "
            << tmStruct->tm_min << " "
            << tmStruct->tm_sec << endl;
            
            time_t diffTime = 1567904460 - time(nullptr);
            cout << diffTime << endl;
        }
    }
}

void shit() {
    // test out mktime
    cout << "start shit test" << endl;
    struct tm * testTM = new struct tm;
    testTM->tm_mon = 8;
    testTM->tm_mday = 7;
    testTM->tm_year = 119;
    testTM->tm_hour = 6;
    testTM->tm_min = 1;
    testTM->tm_sec = 0;
    cout
    << testTM->tm_mon + 1 << " "
    << testTM->tm_mday << " "
    << testTM->tm_year + 1900 << " "
    << testTM->tm_hour << " "
    << testTM->tm_min << " "
    << testTM->tm_sec << endl;
    delete testTM;
}


///////////////////////////////////////////////////////////
//  MAIN
///////////////////////////////////////////////////////////

int main(int, char**) {
    
    cout << endl << "********************************* timer start main *********************************" << endl << endl;

    //timer_test();

    shit();

    cout << endl << "********************************* end main *********************************" << endl << endl;

    //poop();

    //crap(1);
    
    return 0;
}