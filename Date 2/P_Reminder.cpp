// CS3270 Vanderbilt University
// Prof. Roth
// Name: Breckinridge Stodghill
// VunetID: stodghbs
// email: breckinridge.s.stodghill@vanderbilt.edu
// HW 3
// Date: 02/08/2017

#ifndef P_REMINDER_CPP
#define P_REMINDER_CPP

#include "P_Reminder.h"
#include <string>

PriorityReminder::PriorityReminder() {
    // nothing to do
}


PriorityReminder::PriorityReminder(const Date &d, const std::string &m)
        : Reminder(d, m) {
    // nothing else to do
}

PriorityReminder::~PriorityReminder(){}

void PriorityReminder::print(std::ostream &out) const {
    out << "On " << getDate() << ": <<IMPORTANT>> " << getmsg();
}

std::ostream &operator<<(std::ostream &os, const PriorityReminder &rem) {
    rem.print(os);
    return os;
}


#endif
