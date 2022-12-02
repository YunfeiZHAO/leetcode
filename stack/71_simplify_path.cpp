#include <iostream>
#include <string>
#include <stack>

using namespace std;


string simplifyPath1(string path) {
    stack<string> path_stack;
    string temp = "";
    string unix_path = "";
    char c;

    for(auto i=path.cbegin(); i!=path.cend(); i++) {
        c = *i;
        if(!(c=='/') || next(i) == path.end()) {
            temp.push_back(c);
        } else {
            if(temp.length()==0) {
                continue;
            }else if(temp=="..") {
                if(!path_stack.empty()) { path_stack.pop(); }
            }else if(!(temp==".")) {
                path_stack.push(temp);
            }
            temp = "";
        }
    }
    if(temp.back() == '/') {temp.pop_back();}
    if(temp.length()!=0) {
       if(temp=="..") { if(!path_stack.empty()) { path_stack.pop();} } 
       else if(!(temp==".")) { path_stack.push(temp); }
    }

    while(!path_stack.empty()) {
        temp = path_stack.top();
        path_stack.pop();
        unix_path = temp + "/" + unix_path;
    }
    unix_path = "/" + unix_path;
    if(unix_path.length() > 1) { unix_path.pop_back(); }
    return unix_path;
}


string simplifyPath2(string path) {
    // .. means directory up a level 
    // a period '.' refers to the current directory, 
    // so ignore . handle ..
    //  "/a/./b/../../c/"
    // /c
    // 不要一個一個看 一串一串看 
    // 也不要一直push進stack 先check 再push
    stack<string> s;
    // maintain index i
    for(int i=0;i<path.size();i++){
        cout << i;
        if(path[i]=='/') continue;

        string tmp;
        while(i<path.size() && path[i]!='/'){
            tmp += path[i++];
        }

        if(tmp==".") { continue; }
        if(tmp==".."){ if(!s.empty()) s.pop(); }
        else { s.push(tmp); }
    }

    string ans;
    while(!s.empty()){
        ans = '/'+s.top() + ans;
        s.pop();
    }
    if(ans.size()==0) ans = "/";
    return ans;
}


int main() {
    //string str = "/a/./b/../../c/";
    //string str = "/asd/ds/./fdsdf/";
    //string str = "/../";
    string str = "/a//b////c/d//././/..";
    //string str = "/a/..";
    string result = simplifyPath2(str);

    cout << result << "\n";
}