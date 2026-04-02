#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int xor_all = 0;

    // Step 1: XOR all elements
    for (int x : arr)
    {
        xor_all ^= x;
    }

    // Step 2: Find rightmost set bit
    int set_bit = xor_all & (-xor_all);

    int num1 = 0, num2 = 0;

    // Step 3: Divide into two groups
    for (int x : arr)
    {
        if (x & set_bit)
            num1 ^= x;
        else
            num2 ^= x;
    }

    // Output format
    if (num1 < num2)
        cout << num1 << " and " << num2;
    else
        cout << num2 << " and " << num1;

    return 0;
}
