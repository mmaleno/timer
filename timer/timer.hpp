/**
 * \file timer.hpp
 * \authors Max Maleno [mmaleno@hmc.edu]
 * \brief Timer class interface & encoding
 *
 * \details Created 12/27/19, last updated 12/27/19
 */

#ifndef TIMER_HPP_INCLUDED
#define TIMER_HPP_INCLUDED

#include <iostream>
#include <ostream>

// description of class
class Timer {
 // Interface
 public:
    // Constructor(s)
    Timer();

    // Gets & Sets
    int get_placeholder0();
    int get_placeholder1();

    // Member functions
    void example_function();

 // Encoding
 private:
    // Data members
    int placeholder0_;
    int placeholder1_;

    // Helper functions

};

#endif     // TIMER_HPP_INCLUDED