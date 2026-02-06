#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

inline int mapToInt(char c)
{
    return c - 'a';
}

bool areAnnagrams(string s1, string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();
    
    if(n1 != n2) return false;
    
    vector<int> count1(26, 0);
    vector<int> count2(26, 0);
    
    for(int i = 0; i < n1; i++)
    {
        count1[mapToInt(s1[i])]++;
        count2[mapToInt(s2[i])]++;
    }
    
    for(int i = 0; i < 26; i++)
        if(count1[i] != count2[i]) return false;
    
    return true;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    areAnnagrams(s1, s2) ? cout << "YES" : cout << "NO";
    return 0;
}
