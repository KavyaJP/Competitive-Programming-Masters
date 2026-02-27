#include <bits/stdc++.h>
using namespace std;

vector<int> build_prefix_sum_array(vector<int> &v)
{
    int n = v.size();
    vector<int> prefix(n);

    prefix[0] = v[0];

    for (int i = 1; i < n; i++)
        prefix[i] = v[i] + prefix[i - 1];

    return prefix;
}

int sum_query(vector<int> &prefix, int l, int r)
{
    if (l == 0)
        return prefix[r];
    else
        return prefix[r] - prefix[l - 1];
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> prefix_sum = build_prefix_sum_array(v);
    int l = 1, r = 4;
    cout << "sum query for " << l << " and " << r << " is: " << sum_query(prefix_sum, l, r);
    return 0;
}