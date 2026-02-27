#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestIncreasingSubsequence(vector<int> arr)
{
    if (arr.empty())
        return 0;

    vector<int> tails;

    for (int x : arr)
    {
        auto it = lower_bound(tails.begin(), tails.end(), x);

        if (it == tails.end())
        {
            tails.push_back(x);
        }
        else
        {
            *it = x;
        }
    }

    return tails.size();
}

int main()
{
    int n;
    if (!(cin >> n))
        return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr) << endl;

    return 0;
}