#include <iostream>
#include <vector>

using namespace std;

/**
 * Given an array, rotate the array to the right by k steps, where k is non-negative.
*/

// O(n) extra space
void rotate1(vector<int>& nums, int k) {  
    int l = nums.size();
    vector<int> r(l);
    for(int i=0; i<l; i++) {
        r[(i+k) % l] = nums[i];
    }
    nums = r;
}

// O(1) extra space, reverse() is O(1) extra memory
void rotate2(vector<int>& nums, int k) {  
    int l = nums.size();
    k = k % l;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}


int main() {
    int k = 0;
    vector<int> nums = {-3,1,5,6};
    
    //vector<int> nums = {-1};

    rotate2(nums, k);
    cout << "result: ";
    for (const auto& i: nums) {cout << i << ' ';}
    return 0;
}

