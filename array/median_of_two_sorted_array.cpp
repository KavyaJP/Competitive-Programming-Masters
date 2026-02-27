#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> merged;
    for (int i = 0; i < nums1.size(); i++)
        merged.push_back(nums1[i]);

    for (int i = 0; i < nums2.size(); i++)
        merged.push_back(nums2[i]);

    sort(merged.begin(), merged.end());

    int n = merged.size();

    double ans = n % 2 != 0 ? merged[n / 2] : (merged[n / 2 - 1] + merged[n / 2]) / 2.0;

    return ans;
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;

    vector<int> vec1(n1);
    vector<int> vec2(n2);

    for (int i = 0; i < n1; i++)
        cin >> vec1[i];

    for (int i = 0; i < n2; i++)
        cin >> vec2[i];

    cout << findMedianSortedArrays(vec1, vec2);
    return 0;
}
