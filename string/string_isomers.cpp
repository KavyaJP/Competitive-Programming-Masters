#include <bits/stdc++.h>
using namespace std;

bool areIsomers(string s1, string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();
    if(! n1 == n2)
        return false;
    
    unordered_map<char,char> map;

    for(int i = 0; i < n1; i++)
    {
        // if the character is new
        if(!map.count(s1[i]))
        {
            map.insert({s1[i], s2[i]});
            continue;
        }

        // now that we know the character s1[i] is in map, then we check if s2[i] is the value of the key s1[i]
        if(map[s1[i]] != s2[i])
            return false;
        
        // now we do that s1[i] is in map, it does have s2[i] as it's pair, meaning for this iteration, our values are one to one mapped, meaning our two strings are isomers
    }
    return true;
}

int main()
{
    string s1 = "abc";
    string s2 = "def";

    if(areIsomers(s1, s2))
        cout << s1 << " & " << s2 << " are isomers." << endl;
    else
        cout << s1 << " & " << s2 << " are not isomers." << endl;

    return 0;
}