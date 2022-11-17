//
// Created by yunfei on 07/11/2022.
//

#include <iostream>
#include <vector>

using namespace std;

// my version
int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int middle;
    while(right > left) {
        middle = left + (right - left) / 2;
        if(nums[middle] == target) {return middle;}
        else if(nums[middle] < target) {left = middle + 1;}
        else{right = middle;}
    }
    // left and right converge to a value
    if(target > nums[left]) {return nums.size();}
    else {return left;}

}

// better version
// if bigger than the last one, the right part will not change
int searchInsert2(vector<int>& nums, int target) {
    int l = 0, r = nums.size();
    while(l < r) {
        int m = l + (r - l) / 2;
        if(target > nums[m]) {
            l = m + 1;
        }
        else {
            r = m;
        }
    }
    return l;
}




int main() {
    vector<int> nums = {1,3,5,6};
    int target = 0;
    auto r = searchInsert2(nums, target);
    cout << "result: " << r << "\n";
    return 0;
}