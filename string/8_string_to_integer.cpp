#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <climits>

using namespace std;

int myAtoi(string s) {
    int start=0, new_start=0, length=0, new_length=0, neg=0, num=0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] >= '0' && s[i] <= '9' ? 1 : 0) {
            if(length==0) {start = i;}
            length++;
        } else {
            if(length>0) {break;}
        }
    }
    
    neg = (start==0 || s[start - 1]!='-') ? 0:1;
    new_start = start;
    new_length = length;
    for(int i=start; i<start+length; i++) {
        if(s[i] == 0) {
            new_start++;
            new_length--;
        }
    }

    for(int i=new_start; i<new_start+new_length; i++) {
        num += (s[i] - '0') * pow(10, new_start+new_length-i-1);
    }
    num = neg? -num:num;
    return num;
}


int myAtoi2(string s) {
    int i = 0, sign = 1, v   = 0;
    while (s[i] == ' ') i++;
    if (s[i] == '-') sign = -1, i++;
    else if (s[i] == '+') sign = 1, i++;
    while (s[i] >= '0' && s[i] <= '9') {
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] - '0' > 7)) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        num = num * 10 + (s[i] - '0');
        i++;
    }
    return num * sign;
    }

int main() {

    // string str = "42";
    // string str = "   -42";
    // string str = "4193 with words";
    string str = "words and 987";
    int result = myAtoi2(str);
    cout << result << endl;
}