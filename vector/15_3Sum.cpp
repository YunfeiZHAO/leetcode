#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool existence(vector<vector<int>> tuples, vector<int> tuple) {
    for(auto t1=tuples.begin(); t1<tuples.end(); t1++) {
        bool existence=true;
        for(int i=0; i<2;i++) {
            if(find(t1->begin(), t1->end(), tuple[i]) == t1->end()) {existence = false;}
            else {}
        }
        if(existence==true) {return true;}
    }
    return false;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    int len=nums.size();
    vector<vector<int>> result;
    for(int i=0; i<len-2; i++) {
        for(int j=i+1; j<len-1; j++) {
            for(int k=j+1; k<len; k++) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> new_triple {nums[i], nums[j], nums[k]};
                    if(!existence(result, new_triple)) {
                        result.push_back(new_triple);
                    }
                }
            }
        }
    }
    return result;
}

int main(int argc, char* argv[]){
    vector<int> nums{-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector<vector<int>> result = threeSum(nums);

    for(auto it1=result.begin(); it1<result.end(); it1++) {
        for(auto it2=it1->begin(); it2<it1->end(); it2++) {
            cout << *it2;
        }
        cout<<endl;
    }
    return 0;
}