#include <iostream>
#include <vector>

using namespace std;

/**
* https://leetcode.com/problems/reverse-string/?envType=study-plan&id=algorithm-i
*/

void reverseString(vector<char>& s) {
    char temp;
    int l = s.size();
    for(int i=0; i<l/2; i++) {
        temp = s[i];
        s[i] = s[l - i -1];
        s[l - i -1] = temp;
    }
}

int main() {
    vector<char> nums = {'w', 'h', 'a', 't'};
    //vector<int> nums = {-1};

    reverseString(nums);

    cout << "result: ";
    for (const auto& i: nums) {cout << i << ' ';}
    return 0;
}


