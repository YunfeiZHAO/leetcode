/**
 * A knowledge combing for reference and combing in c++
*/

#include <iostream>

using namespace std;

void ref_init() {
    int ival = 1024;
    int jval = 50;
    cout << "ival: " << ival << "\n";
    cout << "ival address: " << &ival << "\n";

    int &refVal = ival;
    int &refVal2 = jval;

    cout << "Reference: " << refVal << "\n";
    cout << "Reference address: " << &refVal << "\n";

    refVal = 4;
    cout << "Changed original value: " << ival;

    // Not assignable
    // &refVal2 = &refVal;

}

int main() {
    ref_init();
}