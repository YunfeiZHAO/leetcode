#include <iostream>
#include <string>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int l1 = nums1.size(), l2 = nums2.size(), p1 = 0, p2 = 0, v1, v2; 
    int pos = (l1+l2-1)/2; //least median element
    if(l1 == 0) {
        v1 = nums2[pos];
        if(l2 >=2) {v2 = nums2[pos + 1];}
        else {v2 = v1;}
        
    } else if(l2 == 0) {
        v1 = nums1[pos];
        if(l1 >=2) {v2 =  nums1[pos + 1];}
        else {v2 = v1;}
        
    } else{
        v1 = v2 = min(nums1[0], nums2[0]);
        while(p1 + p2 <= pos + 1) { //p1, p2 -> pos, pos+1 
            v1 = v2;
            if(p1 >= l1) {
                v2 = nums2[p2];
                p2++;
            }else if(p2 >= l2) {
                v2 = nums1[p1];
                p1++;
            }else if(nums1[p1] <= nums2[p2]) {
                v2 = nums1[p1];
                p1++;
            }
            else {
                v2 = nums2[p2];
                p2++;
            }
        }
    }
    if((l1+l2) % 2 == 0) {return float(v1 + v2)/2;}
    else {return min(v1, v2);}
}

int main() {
    // vector<vector<int>> grid {{1,1,1}, {1,1,1}, {1,1,1}};
    //vector<int> nums1 {1,2,3}, nums2 {5,6,7};
    //vector<int> nums1 {1,2,3}, nums2 {};
    // vector<int> nums1 {1,3}, nums2 {2};

    // vector<int> nums1 {}, nums2 {1};
    // double re = findMedianSortedArrays(nums1, nums2);
    // cout << "re: " << re << endl;
    int r = 8;
    char c1='9', c2='1';
    cout << int(c1);
}
