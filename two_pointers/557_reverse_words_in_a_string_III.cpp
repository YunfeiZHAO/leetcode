#include <iostream>
#include <vector>

using namespace std;

/**
* https://leetcode.com/problems/reverse-words-in-a-string-iii/?envType=study-plan&id=algorithm-i
*/

string reverseWords1(string s) {
    int start=0, end=0;
    int l = s.length();
    while(end < l) {
        if(s[end] == ' ') {
            reverse(s.begin() + start, s.begin() + end);
            start = end;
            start++;
        }
        if(end + 1 == l) {reverse(s.begin() + start, s.begin() + l);}
        end++;
        
    }
    return s;
}


string reverseWords2(string s) {
    int l = 0;
    int r;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            r = i - 1;
            while (l < r) swap(s[l++], s[r--]);
            l = i + 1;
        }
    }
    r = s.size() - 1;
    while (l < r) swap(s[l++], s[r--]);
    return s;
}


int main() {
    string s = "This is a dog";

    s = reverseWords2(s);

    cout << "result: " << s << '\n';
    return 0;
}