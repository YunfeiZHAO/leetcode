/**
 * A knowledge combing for structures in c++
*/

#include <iostream>
#include <vector>

using namespace std;

void vec() {
    vector<int> nums = {-3,1,5,6};

    cout << "origin \n";
    for (const auto& i: nums) {cout << i << ' ';}

    cout << "begin pointer \n";
    cout << *nums.begin() << "\n";

    cout << "front \n";
    cout << nums.front() << "\n";

    cout << "end \n";
    cout << *nums.end() << "\n";

    cout << "rbegin \n";
    cout << *nums.rbegin() << "\n";

    cout << "rbegin + 1\n";
    cout << *(nums.rbegin() + 1) << "\n";

    cout << "reverse \n";
    reverse(nums.begin(), nums.begin() + 2);
    for (const auto& i: nums) {cout << i << ' ';}
}

int main() {
    vec();
}