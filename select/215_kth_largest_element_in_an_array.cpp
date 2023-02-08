#include <iostream>
#include <string>
#include <queue>

using namespace std;


/**
 * Quick Select Algorithm
 * mean time complexity O(n) : n + n/2 + n/4 ... = 2n
 * the worst time complexity O(n^2) : n + (n-1) + (n-2) ...
*/
int partition(vector<int>& nums, int l, int r) {
    int p_v = nums[r];
    int p_pos = l;
    int temp;

    for(int i=l; i<r; i++) {
        if(nums[i] <= p_v) {
            temp = nums[p_pos];
            nums[p_pos] = nums[i];
            nums[i] = temp;
            p_pos++;
        }
    }
    // put pivot value to the right place
    temp = nums[p_pos];
    nums[p_pos] = p_v;
    nums[r] = temp;

    // cout << "pivot index: " << p_pos << "\n";
    // for (const auto& i: nums) {cout << i << ' ';}

    // return pivot index
    return p_pos;
}


int findKthLargest(vector<int>& nums, int k) {
    int l = 0, r = nums.size() - 1, p_pos;

    // Partition Function, 
    // all elements on the left of the pivot are smaller than pivot, 
    // all elements on the right are greater
    // l, r are index

    p_pos = partition(nums, l, r);

    while(nums.size() - p_pos != k) {
        if(nums.size() - p_pos > k) {
            l = p_pos + 1;
            p_pos = partition(nums, l, r);
        } else {
            r = p_pos - 1;
            p_pos = partition(nums, l, r); 
        }
    }
    return nums[p_pos];
}


int main() {
    vector<int> nums = {1,3,4,1,5,15,9};
    // partition(nums, 4, 6);
    int k = 5;
    int result = findKthLargest(nums, k);

    cout << result << "\n";
}