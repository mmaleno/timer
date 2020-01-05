/**
 * \file timer.hpp
 * \authors Max Maleno [mmaleno@hmc.edu]
 * \brief Timer class interface & encoding
 *
 * \details Created 12/27/19, last updated 12/30/19
 */


/*  Latest commit:
    - unsure...
*/

/*  TODO:
    - see how tm struct can help us severely
    - implement date to Epoch time
    - add date to Epoch time to each constructor
    - add get date functions
*/


#ifndef TIMER_HPP_INCLUDED
#define TIMER_HPP_INCLUDED

#include <iostream>
#include <ostream>
#include <ctime>

using namespace std;

// Class to support countdown functionality
class Timer {
 // Interface
 public:
   // Constructors
   Timer() = delete;
   Timer(long eventEpochTime);

   /* TO BE IMPLEMENTED */

   // Need to convert from human time to Epoch time
   // using ints to accept pos/neg values, will filter
   // results within constructor
   Timer(int year, char month, char day);
   Timer(int year, char month, char day, char hour, char minute, char second);

   // Member functions

   // Set the time
   void setTime(long eventEpochTime);
   void setYear(int eventYear);
   void setMonth(char eventMonth);
   void setDay(char eventDay);
   void setHour(char eventHour);
   void setMinute(char eventMinute);
   void setSecond(char eventSecond);
   

   /*
      _Needs_ to be run as close as possible
      to use of get-time functions for most
      accurate results.
   */
   void update();

   time_t getEventEpochTime();

   void printEventTime();

   /*
      ...be sure to run update before using
      all of the below get-time functions.
      ints so that values can be negative
   */
   int getDays();
   int getHours();
   int getMinutes();
   int getSeconds();

 // Encoding
 private:
   // Data members 

   /*
      In C++, long has an upper value of 2147483647.
      Storing the Epoch Time in a long is supported until
      January 2038: https://www.Epochtimestamp.com/index.php
      Switched to time_t to be more compatible with ctime
   */
   time_t eventEpochTime_;

   struct tm * eventInfo_;
   /* Info about tm *:   
   eventInfo_ = localtime(&eventEpochTime_);
   eventInfo_->tm_sec --- seconds after the minute [0, 60]
   eventInfo_->tm_min --- minutes after the hour [0, 59]
   eventInfo_->tm_hour --- hours since midnight [0, 23]
   eventInfo_->tm_mday --- day of the month [1, 31]
   eventInfo_->tm_mon --- months since January [0, 11]
   eventInfo_->tm_year --- years since 1900
   eventInfo_->tm_wday --- days since Sunday [0, 6]
   eventInfo_->tm_yday --- days since January 1 [0, 365]
*/

   // Time remaining until event
   int days_;
   int hours_;
   int minutes_;
   int seconds_;

   // Helper functions
};

#endif     // TIMER_HPP_INCLUDED