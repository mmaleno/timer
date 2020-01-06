/**
 * \file timer.cpp
 * \authors Max Maleno [mmaleno@hmc.edu]
 * \brief Timer class implentation
 *
 * \details Created 12/27/19, last updated 01/05/20
 */

/* For latest commit and TODO info, see timer header file */

#include "timer.hpp"

// constructor for exact epoch value
Timer::Timer(time_t eventEpochTime)
    :   eventEpochTime_{eventEpochTime}
{
    if (eventEpochTime > 2147483647) {
        cout << "Warning! Be sure your system"
        << "time_t mitigates Y2038..." << endl;
    }
    localtime_r(&eventEpochTime_, eventInfo_);
    update();
}

// constructor for a day
// ISO 8601 for the win!!
Timer::Timer(int year, int month, int day) {
    // See header file for explanation of members
    eventInfo_->tm_year = year - 1900;
    eventInfo_->tm_mon = month - 1;
    eventInfo_->tm_mday = day;
    eventInfo_->tm_hour = 0;
    eventInfo_->tm_min = 0;
    eventInfo_->tm_sec = 0;
    eventEpochTime_ = mktime(eventInfo_);
    update();
}

// constructor for a time during a certain day
Timer::Timer(int year, int month, int day, int hour, int minute, int second) {
    // See header file for explanation of members
    eventInfo_->tm_year = year - 1900;
    eventInfo_->tm_mon = month - 1;
    eventInfo_->tm_mday = day;
    eventInfo_->tm_hour = hour;
    eventInfo_->tm_min = minute;
    eventInfo_->tm_sec = second;
    eventEpochTime_ = mktime(eventInfo_);
    update();
}

// destructor
Timer::~Timer() { delete eventInfo_; }

// set/change epoch time of event
void Timer::setEpoch(time_t eventEpochTime) {
    eventEpochTime_ = eventEpochTime;
    localtime_r(&eventEpochTime_, eventInfo_);
}

// set/change year of event
void Timer::setYear(int year) {
    if (year >= 2038) {
        cout << "Warning! Be sure your system"
        << "time_t mitigates Y2038..." << endl;
    }
    eventInfo_->tm_year = year;
    eventEpochTime_ = mktime(eventInfo_);
}

// set/change month of event
void Timer::setMonth(int month) {
    eventInfo_->tm_mon = month - 1;
    eventEpochTime_ = mktime(eventInfo_);
}

// set/change day of event
void Timer::setDay(int day) {
    eventInfo_->tm_mday = day;
    eventEpochTime_ = mktime(eventInfo_);
}

// set/change hour of event
void Timer::setHour(int hour) {
    eventInfo_->tm_hour = hour;
    eventEpochTime_ = mktime(eventInfo_);
}

// set/change minute of event
void Timer::setMinute(int minute) {
    eventInfo_->tm_min = minute;
    eventEpochTime_ = mktime(eventInfo_);
}

// set/change second of event
void Timer::setSecond(int second) {
    eventInfo_->tm_sec = second;
    eventEpochTime_ = mktime(eventInfo_);
}

// get event's Epoch time
time_t Timer::getEventEpochTime() {
    return eventEpochTime_;
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

// refresh all time-remaining members
void Timer::update() {
    time_t diffEpochTime = eventEpochTime_ - time(nullptr);

    // calculate time divisions from the amount of remaining seconds until event
    days_ = diffEpochTime / (60*60*24);
    hours_ = (diffEpochTime % (60*60*24)) / (60*60);
    minutes_ = ((diffEpochTime % (60*60*24)) % (60*60)) / 60;
    seconds_ = (((diffEpochTime % (60*60*24)) % (60*60)) % 60);
}

// overload operator for timer object
std::ostream& operator<<(std::ostream& os, const Timer& t) {
    os
    << "Ev Ep: " << t.eventEpochTime_ << endl
    << "Ev Yr: " << t.eventInfo_->tm_year + 1900 << endl
    << "Ev Mo: " << t.eventInfo_->tm_mon + 1 << endl
    << "Ev D: " << t.eventInfo_->tm_mday << endl
    << "Ev Hr: " << t.eventInfo_->tm_hour << endl
    << "Ev Min: " << t.eventInfo_->tm_min << endl
    << "Ev Sec: " << t.eventInfo_->tm_sec << endl
    << "Rem D: " << t.days_ << endl
    << "Rem Hr: " << t.hours_ << endl
    << "Rem Min: " << t.minutes_ << endl
    << "Rem Sec: " << t.seconds_ << endl;

    return os;
}
