// CS3270 Vanderbilt University
// Prof. Roth
// Name: Breckinridge Stodghill
// VunetID: stodghbs
// email: breckinridge.s.stodghill@vanderbilt.edu
// HW 3
// Date: 02/08/2017

#ifndef REMINDER_H
#define REMINDER_H

#include "Date.h"
#include <string>
#include <iostream>


class Reminder : public Date {
private:
    std::string msg;
public:
    Reminder();  //default ctor

    Reminder(const Date &d, const std::string &m = "");  //alt ctor

    // Reminder(const Reminder &); //default copy ctor is sufficient
    virtual ~Reminder();  //default dtor is sufficient

    void setmsg(const std::string &m);

    std::string getmsg(void) const;

    virtual void print(std::ostream &out = std::cout) const;
};

std::ostream &operator<<(std::ostream &os, const Reminder &rem);

#endif
