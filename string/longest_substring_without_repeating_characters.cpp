#include <bits/stdc++.h>
using namespace std;

int longest_substring_without_repeating_characters(string s)
{
    unordered_map<char, int> lastIndex;
    int maxLength = 0;
    int left = 0;

    for (int right = 0; right < s.length(); right++)
    {
        if (lastIndex.count(s[right]) && lastIndex[s[right]] >= left)
            left = lastIndex[s[right]] + 1;
        lastIndex[s[right]] = right;
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main()
{
    string s = "pwwkew";
    cout << "Length of longest substring without repeating character: "
         << longest_substring_without_repeating_characters(s) << endl;
    return 0;
}
