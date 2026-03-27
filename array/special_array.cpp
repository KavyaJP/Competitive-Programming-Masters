// The array is considered special if there are X elements greater than X.

#include <bits/stdc++.h>
using namespace std;

int specialArray(vector<int> &nums)
{
    int n = nums.size();

    for (int x = 0; x <= n; x++)
    {
        int count = 0;

        for (int num : nums)
        {
            if (num >= x)
            {
                count++;
            }
        }

        if (count == x)
        {
            return x;
        }
    }

    return -1;
}

int main()
{
    string input;
    getline(cin, input);

    vector<int> nums;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, ','))
    {
        nums.push_back(stoi(temp));
    }

    cout << specialArray(nums) << endl;

    return 0;
}