#include <iostream>
#include <vector>


using namespace std;
/* https://leetcode.com/problems/binary-search/?envType=study-plan&id=algorithm-i
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. 
If target exists, then return its index. Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity.
*/

int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int middle;
    while(right >= left) { 
      middle = (left + right) / 2;
      if(target == nums[middle]) {return middle;}
      else if(target < nums[middle]) {right = middle - 1;}
      else {left = middle + 1;}
    }
    return -1;
}


int main() {
  vector<int> nums = {3, 5, 10, 20, 50};
  int target = 5;
  int i = search(nums, target);
  cout << "indice:  " << i << "\n";
  return 0;
}