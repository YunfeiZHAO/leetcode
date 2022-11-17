#include <iostream>
#include<cmath>

#include <vector>

using namespace std;

/* https://leetcode.com/problems/squares-of-a-sorted-array/?envType=study-plan&id=algorithm-i
 * Input: nums = [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
*/

// O(n^2) version
vector<int> sortedSquares(vector<int>& nums) {
    vector<int> square_array;
    for(const auto & n: nums) {
        int n_s = pow(n, 2);
        int l = square_array.size();
        bool inserted = false;
        for(int i = 0; i < l; i++) {
            if(square_array[i] >= n_s) {
                square_array.insert(square_array.begin() + i, n_s);
                inserted = true;
                break;
            }
        }
        if(!inserted) {square_array.push_back(n_s);}
    }
    return square_array;

}

// O(n) version with two pointers

vector<int> sortedSquares2(vector<int>& nums) {
    int begin = 0;
    int end = nums.size() - 1;
    vector<int> square_array(nums.size());
    int i = end;

    while(end >= begin) {
        if(abs(nums[end]) >= abs(nums[begin])) {
            square_array[i] = nums[end] * nums[end];
            end--;
        } else {
            square_array[i] = nums[begin] * nums[begin];
            begin++;
        }
        i--;
    }
    return square_array;
}

int main() {
    vector<int> nums = {-3,1,5,6};

    auto r = sortedSquares2(nums);
    cout << "result: ";
    for (const auto& i: r) {cout << i << ' ';}
    return 0;
}