#include <iostream>
#include <string>
#include <vector>

using namespace std;

// C++ program to demonstrate
// min heap for priority queue
#include <iostream>
#include <queue>
using namespace std;
 
void showpq(priority_queue<int, vector<int>, greater<int> > gq)
{
    priority_queue<int, vector<int>, greater<int> > g = gq;
    while (!g.empty()) {
        cout << ' ' << g.top();
        g.pop();
    }
    cout << '\n';
}
 
void showArray(int* arr, int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
 
// Driver Code
int main()
{
    int arr[6] = { 10, 2, 4, 8, 6, 9 };
    priority_queue<int, vector<int>, greater<int> > gquiz(arr, arr + 5);
 
    cout << "Array: ";
    showArray(arr, 6);
 
    cout << "Priority Queue : ";
    showpq(gquiz);
 
    return 0;
}




class Solution:
    def intToRoman(self, num: int) -> str:
        d = {1000: 'M', 900: 'CM', 500: 'D', 400: 'CD', 100: 'C', 90: 'XC', 50: 'L', 40: 'XL', 10: 'X', 9: 'IX', 5: 'V', 4: 'IV', 1: 'I'} 
        
        res = ""
        
        for i in d:
            res += (num//i) * d[i]
            num %= i
        
        return res