#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool checkPallindrome(string s)
{
    int start = 0;
    int end = s.length() - 1;
    
    while(start < end)
    {
        if(s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}


int main() {
    string s;
    cin >> s;
    checkPallindrome(s) ? cout << "true" : cout << "false";
    return 0;
}