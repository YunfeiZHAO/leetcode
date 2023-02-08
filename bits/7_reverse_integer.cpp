#include <iostream>
#include <string>
#include <queue>

using namespace std;

int reverse(int x) {
    bool isNeg = false;
    int reverse = 0;
    while(x != 0) {
        if(reverse > INT_MAX/10 || (reverse == INT_MAX/10 && x % 10 > 7)) {return 0;}
        if(reverse < INT_MIN/10 || (reverse == INT_MIN/10 && x % 10 < -8)) {return 0;}
        reverse = reverse * 10 + x % 10; //danger zone as it can overflow
        x /= 10;
    }
    return reverse;
}


int main() {
    int re = reverse(-123);
    cout << "result: " << re << endl;
    // cout << -7%10 << endl;
    return 0;
}