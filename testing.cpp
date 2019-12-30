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
#include "timer/timer.hpp"

using namespace std;

///////////////////////////////////////////////////////////
//  TESTS
///////////////////////////////////////////////////////////

// test template

void timer_test() {
    Timer test = Timer(1567904460);
    test.update();
    cout << test.getEventUnixTime() << endl;
    cout << test.getDays() << endl;
    cout << test.getHours() << endl;
    cout << test.getMinutes() << endl;
    cout << test.getSeconds() << endl;
    //assert(test.get_placeholder1() == 2);
    cout << "template_test passed!" << endl;
}

///////////////////////////////////////////////////////////
//  MAIN
///////////////////////////////////////////////////////////

int main(int, char**) {
    cout << endl << "********************************* timer start main *********************************" << endl << endl;

    timer_test();

    cout << endl << "********************************* end main *********************************" << endl << endl;

    return 0;
}