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
    - port update from old c code to this class
    - implement date to unix time
    - add date to unix time to each constructor
    - add get date functions
*/


#ifndef TIMER_HPP_INCLUDED
#define TIMER_HPP_INCLUDED

// Class to support countdown functionality
class Timer {
 // Interface
 public:
   // Constructors
   Timer() = delete;  // Set everything to zero
   Timer(long eventUnixTime);
   // Set eventUnixTime_, calculate day/month/year

   /* TO BE IMPLEMENTED

   // Need to convert from human time to unix time
   // using ints to accept pos/neg values, will filter
   // results within constructor
   Timer(int year, char month, char day);
   Timer(int year, char month, char day, char hour, char minute, char second);

   // Member functions

   // Set the time
   void setTime(long eventUnixTime);
   void setYear(int eventYear);
   void setMonth(char eventMonth);
   void setDay(char eventDay);
   void setHour(char eventHour);
   void setMinute(char eventMinute);
   void setSecond(char eventSecond);


   */
   

   /*
      _Needs_ to be run as close as possible
      to use of get-time functions for most
      accurate results.
   */
   void update();

   long getEventUnixTime();

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

   // Event's time parameters, to convert to Unix Time
   // Need to make sure these values make sense
   int eventYear_;
   char eventMonth_;
   char eventDay_;
   char eventHour_;
   char eventMinute_;
   char eventSecond_;
   */

   /*
      In C++, long has an upper value of 2147483647.
      Storing the Unix Time in a long is supported until
      January 2038: https://www.unixtimestamp.com/index.php
   */
   long eventUnixTime_;

   // Time remaining until event
   int days_;
   int hours_;
   int minutes_;
   int seconds_;

   // Helper functions
};

#endif     // TIMER_HPP_INCLUDED