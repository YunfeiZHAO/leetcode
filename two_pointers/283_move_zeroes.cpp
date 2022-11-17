#include <iostream>
#include <vector>

using namespace std;

/**
* Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
* Note that you must do this in-place without making a copy of the array.
*/

void moveZeroes(vector<int>& nums) {
    int l = nums.size();
    int i = 0;
    while(l > 0) {
        if(nums[i] == 0) {
            nums.push_back(nums[i]);
            nums.erase(nums.begin() + i);
        } else {
            i++;
        }
        l--;
    }
}


void moveZeroes2(vector<int>& nums) {
    int j = 0;
    for(int i=0; i<nums.size(); i++) {
        if(nums[i] != 0) {
            nums[j++] = nums[i];
        }
    }
    for(; j<nums.size(); j++) {
        nums[j] = 0;
    }
}


int main() {
    vector<int> nums = {-3, 0, 0, 1, 1, 1, 1, 0, 5, 6};
    //vector<int> nums = {-1};

    moveZeroes2(nums);

    cout << "result: ";
    for (const auto& i: nums) {cout << i << ' ';}
    return 0;
}
