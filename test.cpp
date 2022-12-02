#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
    string s1 = "ok";
    string s2 = "oa";
    cout << s1.compare(s2) << '\n';
    //cout << typeid(s1 == s2).name();
    cout << int(s1 == "ok");
    return 0;
}