/**
 * \file timer.cpp
 * \authors Max Maleno [mmaleno@hmc.edu]
 * \brief Timer class implentation
 *
 * \details Created 12/27/19, last updated 12/27/19
 */

#include "timer.hpp"

///////////////////////////////////////////////////////////
//  IMPLEMENTATION
///////////////////////////////////////////////////////////

Timer::Timer()
    :   placeholder0_{1},
        placeholder1_{0}
{
    // constructor tasks
}

int Timer::get_placeholder0() {
    return placeholder0_;
}

int Timer::get_placeholder1() {
    return placeholder1_;
}

void Timer::example_function() {
    placeholder1_ = 2 * placeholder0_;
    std::cout << "timer example function ran" << std::endl;
}
