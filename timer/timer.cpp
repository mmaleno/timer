/**
 * \file timer.cpp
 * \authors Max Maleno [mmaleno@hmc.edu]
 * \brief Timer class implentation
 *
 * \details Created 12/27/19, last updated 12/30/19
 */

 /* For latest commit and TODO info, see timer header file */

#include "timer.hpp"

// most commonly used constructor
Timer::Timer(long eventEpochTime)
    :   eventEpochTime_{eventEpochTime},
        eventInfo_{localtime(&eventEpochTime_)},
        days_{0},           // to be set by update
        hours_{0},          // to be set by update
        minutes_{0},        // to be set by update
        seconds_{0}         // to be set by update
{
    update();
}

/* TO BE IMPLEMENTED

// constructor for the day, not the time during the day
Timer::Timer(int year, char month, char day)
    :   eventYear_{year},
        eventMonth_{month},
        eventDay_{day},
        eventHour_{0},
        eventMinute_{0},
        eventSecond_{0},
        eventEpochTime_{0},
        days_{0},
        hours_{0},
        minutes_{0},
        seconds_{0}
{
    // Calculate eventEpochTime_, run update()
}

// constructor for time during a certain day
Timer::Timer(int year, char month, char day, char hour, char minute, char second)
    :   eventYear_{year},
        eventMonth_{month},
        eventDay_{day},
        eventHour_{hour},
        eventMinute_{minute},
        eventSecond_{second},
        eventEpochTime_{0},
        days_{0},
        hours_{0},
        minutes_{0},
        seconds_{0}
{
    // Calculate eventEpochTime_, run update()
}

void Timer::setTime(long eventEpochTime) {
    eventEpochTime_ = eventEpochTime;
    update();
}

void Timer::setYear(int eventYear) {
    eventYear_ = eventYear;
    update();
}

void Timer::setMonth(char eventMonth) {
    eventMonth_ = eventMonth;
    update();
}

void Timer::setDay(char eventDay) {
    eventDay_ = eventDay;
    update();
}

void Timer::setHour(char eventHour) {
    eventHour_ = eventHour;
    update();
}

void Timer::setMinute(char eventMinute) {
    eventMinute_ = eventMinute;
    update();
}

void Timer::setSecond(char eventSecond) {
    eventSecond_ = eventSecond;
    update();
}

*/

// get event's Epoch time
time_t Timer::getEventEpochTime() {
    return eventEpochTime_;
}

void Timer::printEventTime() {
    cout
    << eventInfo_->tm_mon + 1 << " "
    << eventInfo_->tm_mday << " "
    << eventInfo_->tm_year + 1900 << " "
    << eventInfo_->tm_hour << " "
    << eventInfo_->tm_min << " "
    << eventInfo_->tm_sec << endl;
}

// get days remaining in countdown
int Timer::getDays() {
    return days_;
}

// get hours remaining in countdown
int Timer::getHours() {
    return hours_;
}

// get minutes remaining in countdown
int Timer::getMinutes() {
    return minutes_;
}

// get seconds remaining in countdown
int Timer::getSeconds() {
    return seconds_;
}

void Timer::update() {
    long nowEpochTime = (long)time(NULL);
    long diffEpochTime = eventEpochTime_ - nowEpochTime;

    // calculate time divisions from the amount of remaining seconds until event
    days_ = diffEpochTime / (60*60*24);
    hours_ = (diffEpochTime % (60*60*24)) / (60*60);
    minutes_ = ((diffEpochTime % (60*60*24)) % (60*60)) / 60;
    seconds_ = (((diffEpochTime % (60*60*24)) % (60*60)) % 60);
}
