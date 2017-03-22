// CS3270 Vanderbilt University
// Prof. Roth
// Name: Breckinridge Stodghill
// VunetID: stodghbs
// email: breckinridge.s.stodghill@vanderbilt.edu
// HW 3
// Date: 02/08/2017

#ifndef P_REMINDER_H
#define P_REMINDER_H

#include "Reminder.h"
#include <string>
#include <iostream>

class PriorityReminder : public Reminder {
private:
    // nothing
public:
    PriorityReminder();

    PriorityReminder(const Date &d, const std::string &m = "");

    virtual ~PriorityReminder();

    virtual void print(std::ostream &out = std::cout) const;
};

std::ostream &operator<<(std::ostream &os, const PriorityReminder &rem);

#endif
