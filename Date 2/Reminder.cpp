// CS3270 Vanderbilt University
// Prof. Roth
// Name: Breckinridge Stodghill
// VunetID: stodghbs
// email: breckinridge.s.stodghill@vanderbilt.edu
// HW 3
// Date: 02/08/2017

#ifndef REMINDER_CPP
#define REMINDER_CPP

#include "Reminder.h"
#include <string>


Reminder::Reminder() : msg("") {
    //nothing to do
}


Reminder::Reminder(const Date &d, const std::string &m) : Date(d), msg(m) {
    //nothing to do
}


//Reminder::Reminder(const Reminder &r) {} //default copy ctor is sufficient

//Reminder::~Reminder() {}  //default dtor is sufficient

void Reminder::setmsg(const std::string &m) {
    msg.assign(m);
}

std::string Reminder::getmsg(void) const {
    if (!msg.empty())
        return msg;
    else
        return "No Message";
}

Reminder::~Reminder(){}

void Reminder::print(std::ostream &out) const {
    out << "On " << getDate() << ": " << getmsg();
}

std::ostream &operator<<(std::ostream &os, const Reminder &rem) {
    rem.print(os);
    return os;
}


#endif
