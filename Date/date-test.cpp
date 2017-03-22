#include <iostream>
#include "Date.h"

using namespace std;

int main() {


    Date d4;   // get today's date
    d4.setDate("9/14/2016");

    cout << "test1: ";
    cout << d4 << endl;

    cout << "test2: ";
    cout << 2 + d4 << endl;

    cout << "test3: ";
    cout << d4 - 2 << endl;

    cout << "test4: ";
    cout << d4++ << "   ";   // post increment
    cout << d4 << endl;

    cout << "test5: ";
    cout << --d4 << "   ";   // pre decrement
    cout << d4 << endl;

    Date d5(d4);             // call copy constructor
    d4 += 365;               // add 365 days
    cout << "test6: ";
    cout << d4 << endl;

    cout << "test7: ";
    cout << d4 - d5 << endl;   // find difference



      cout << "test8: ";
      if (d4 < "01/01/2016")
         cout << d4 << " is less than " << "01/01/2016" << endl;
      else
         cout << d4 << " is greater than or equal " << "01/01/2016" << endl;



      Date d2(1, 12, 2016);
      Date d3;
      d3.setDate(1, 17, 2016);

      if (d2==d3) {
        cout << d2 << " is equal to " << d3 << endl << endl;
      }
      else if (d2 < d3) {
        cout << d2 << " is earlier than " << d3 << endl;
        cout << "and the number of days between them is: "
         << d3-d2 << endl << endl;
      }
      else if (d2 > d3) {
        cout << d2 << " is later than " << d3 << endl;
        cout << "and the number of days between them is: "
         << d2-d3 << endl << endl;
      }
      else {
        cout << "ERROR!!";
      }

      d2 = d2 + 5;

      if (d2==d3) {
        cout << d2 << " is equal to " << d3 << endl << endl;
      }
      else if (d2 < d3) {
        cout << d2 << " is earlier than " << d3 << endl;
        cout << "and the number of days between them is: "
         << d3-d2 << endl << endl;
      }
      else if (d2 > d3) {
        cout << d2 << " is later than " << d3 << endl;
        cout << "and the number of days between them is: "
         << d2-d3 << endl << endl;
      }
      else {
        cout << "ERROR!!";
      }




// enable the following lines to keep your terminal window open
// after running the program if using a terminal window
//    cout << "\n\nPress enter to exit" << endl;
//    cin.get();
    return 0;
}
