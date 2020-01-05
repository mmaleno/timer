/**
 * \file testing.cpp
 * \authors Max Maleno [mmaleno@hmc.edu]
 * \brief Testing script for the timer class
 *
 * \details Created 12/27/19, last updated 01/05/20
 */

#include <iostream>
#include <ostream>
#include <cassert>
#include <ctime>
#include "timer/timer.hpp"

using namespace std;

///////////////////////////////////////////////////////////
//  TESTS
///////////////////////////////////////////////////////////

// test template

void timer_test() {
    Timer test = Timer(1567904460);
    test.update();
    /*
    cout << test.getEventEpochTime() << endl;
    cout << test.getDays() << endl;
    cout << test.getHours() << endl;
    cout << test.getMinutes() << endl;
    cout << test.getSeconds() << endl;
    test.printEventTime();
    */
    cout << test << endl;
    //assert(test.get_placeholder1() == 2);
    cout << "timer_test passed!" << endl;
}

void test_constructor_epoch() {
    cout << "start test_constructor_epoch" << endl;
    Timer test = Timer(1567904460);
    cout << test;
    cout << "end test_constructor_epoch" << endl << endl;
}

void test_constructor_date() {
    cout << "start test_constructor_date" << endl;
    Timer test = Timer(2019, 9, 7);
    cout << test;
    cout << "end test_constructor_date" << endl << endl;
}

void test_constructor_datetime() {
    cout << "start test_constructor_datetime" << endl;
    Timer test = Timer(2019, 9, 7, 21, 1, 0);
    cout << test;
    cout << "end test_constructor_datetime" << endl << endl;
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
    //struct tm * testTM = new struct tm;
    struct tm testTM;
    testTM.tm_mon = 8;
    testTM.tm_mday = 7;
    testTM.tm_year = 119;
    testTM.tm_hour = 0;
    testTM.tm_min = 0;
    testTM.tm_sec = 0;
    cout << "before mktime" << endl;
    cout
    << testTM.tm_mon + 1 << " "
    << testTM.tm_mday << " "
    << testTM.tm_year + 1900 << " "
    << testTM.tm_hour << " "
    << testTM.tm_min << " "
    << testTM.tm_sec << " "
    << testTM.tm_wday << " "
    << testTM.tm_yday << " "
    << testTM.tm_isdst << endl;
    cout << "after mktime" << endl;
    time_t crack = mktime(&testTM);
    cout
    << testTM.tm_mon + 1 << " "
    << testTM.tm_mday << " "
    << testTM.tm_year + 1900 << " "
    << testTM.tm_hour << " "
    << testTM.tm_min << " "
    << testTM.tm_sec << " "
    << testTM.tm_wday << " "
    << testTM.tm_yday << " "
    << testTM.tm_isdst << endl;
    cout << "crack: " << crack << endl;
    //delete testTM;
}


///////////////////////////////////////////////////////////
//  MAIN
///////////////////////////////////////////////////////////

int main(int, char**) {
    
    cout << endl << "********************************* timer start main *********************************" << endl << endl;
    
    //timer_test();
    test_constructor_epoch();
    test_constructor_date();
    test_constructor_datetime();
    //shit();

    //heroin();

    cout << endl << "********************************* end main *********************************" << endl << endl;    
    return 0;
}