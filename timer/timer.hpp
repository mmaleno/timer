/**
 * \file timer.hpp
 * \authors Max Maleno [mmaleno@hmc.edu]
 * \brief Timer class interface & encoding
 *
 * \details Created 12/27/19, last updated 01/05/20
 */

/*  Latest commit:
    - fixed segfault error by tweaking encoding
    - added comments
*/

/*  TODO:
    - implement getEventInfo
    - explore why third constructor still doesn't match up
      using method from last night
    - finish testing file / example functions
*/

#ifndef TIMER_HPP_INCLUDED
#define TIMER_HPP_INCLUDED

#include <iostream>
#include <ctime>

using namespace std;

// Class to support countdown functionality
class Timer {
 public:
   Timer() = delete;
   Timer(time_t eventEpochTime);
   Timer(int year, int month, int day);
   Timer(int year, int month, int day, int hour, int minute, int second);
   ~Timer();

   // Set time fields post object-initialization
   void setEpoch(time_t eventEpochTime);
   void setYear(int year);
   void setMonth(int month);
   void setDay(int day);
   void setHour(int hour);
   void setMinute(int minute);
   void setSecond(int second);

   /*
      _Needs_ to be run as close as possible
      to use of get-time functions for most
      accurate results.
   */
   void update();

   time_t getEventEpochTime();

   tm getEventInfo();   //TODO: need to implement/test

   /*
      Be sure to run update before using
      all of the below get-time functions.
   */
   int getDays();
   int getHours();
   int getMinutes();
   int getSeconds();

   // friend allows this function to access private data members
   friend std::ostream& operator<<(std::ostream& os, const Timer& t);

 private:
   time_t eventEpochTime_;
   tm* eventInfo_ = new tm;
   /* Info about tm *:

   eventInfo_ = localtime(&eventEpochTime_); --- to get time info from epoch value
   localtime_r(&eventEpochTime_, eventInfo_); --- thread-safe method


   tm_sec --- seconds after the minute [0, 60]
   tm_min --- minutes after the hour [0, 59]
   tm_hour --- hours since midnight [0, 23]
   tm_mday --- day of the month [1, 31]
   tm_mon --- months since January [0, 11]
   tm_year --- years since 1900
   tm_wday --- days since Sunday [0, 6]
   tm_yday --- days since January 1 [0, 365]

   To update epoch value and eventInfo_ fields from datetime. Opposite of locatime.
   eventEpochTime_ = mktime(eventInfo_); // update epoch value, fill out eventInfo_
   */

   // Time remaining until event
   int days_;
   int hours_;
   int minutes_;
   int seconds_;
};

// allows printout of timer object
std::ostream& operator<<(std::ostream& os, const Timer& t);

#endif     // TIMER_HPP_INCLUDED
