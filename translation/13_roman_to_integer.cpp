#include <iostream>
#include <map>

using namespace std;


int romanToInt(string s) {
    int n = 0, n1, n2;
    map<char, int> dict { { 'I', 1}, 
                          { 'V', 5},
                          { 'X', 10},
                          { 'L', 50},
                          { 'C', 100},
                          { 'D', 500},
                          { 'M', 1000} };
    int i;
    for(i=0; i<s.length()-1; i++) {
        n1=dict[s[i]];
        n2=dict[s[i+1]];
        if(n1<n2) {
            n += n2 - n1;
            i++;
        }
        else {n += n1;}
    }
    if(!(i >= s.length())) {n += dict[s.back()];}
    return n;
}


int main() {
    string s = "MCMXCIV";
    // string s = "MDCXCV";
    int result = romanToInt(s);
    cout << "result: " << result;
}