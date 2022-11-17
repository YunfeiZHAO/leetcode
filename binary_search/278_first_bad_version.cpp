//
// Created by yunfei on 06/11/2022.
//

#include <iostream>
#include <vector>


using namespace std;
/* https://leetcode.com/problems/first-bad-version/?envType=study-plan&id=algorithm-i
 * n element, elements from the mth are bad, find the first bad one.
*/


int m = 1;

bool isBadVersion(int version) {
    if(version >= m) {return true;}
    else {return false;}
}


// O(N) version
//int firstBadVersion(int n) {
//    if(isBadVersion(1)) {return 1;}
//    for(int i=1; i < n; i++) {
//        if(!isBadVersion(i) && isBadVersion(i+1)) {return i+1;}
//    }
//    if(isBadVersion(n)) {return n;}
//
//}


// my O(log(n)) veresion
//int firstBadVersion(int n) {
//    if(n==1) {return 1;}
//    int left= 1;
//    int right = n;
//    int middle;
//    bool b_m, b_m_p;
//
//    while(right >= left) {
//        middle = left + (right - left) / 2;
//        b_m = isBadVersion(middle);
//        b_m_p = isBadVersion(middle + 1);
//        if (b_m && b_m_p) {
//            right = middle - 1;
//            if (right <= 0) {return 1;}
//        }
//        else if (!b_m && !b_m_p) { left = middle + 1;}
//        else if (!b_m && b_m_p) {  return middle + 1;}
//    }
//    return -1;
//}


int firstBadVersion(int n) {
    int low = 1;
    int high = n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (!isBadVersion(mid)) low = mid + 1;
        else high = mid;
    }
    return low;
}

int main() {
    int r = firstBadVersion(2);
    cout << "first bad:  " << r << "\n";
    return 0;
}