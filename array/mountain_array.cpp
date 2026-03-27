#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int i = 0;

    // Step 1: climb up
    while (i + 1 < n && arr[i] < arr[i + 1])
    {
        i++;
    }

    // Peak cannot be first or last
    if (i == 0 || i == n - 1)
    {
        cout << "false" << endl;
        return 0;
    }

    // Step 2: go down
    while (i + 1 < n && arr[i] > arr[i + 1])
    {
        i++;
    }

    // Check if reached end
    if (i == n - 1)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}