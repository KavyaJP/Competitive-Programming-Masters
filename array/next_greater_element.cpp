#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void printNextGreaterElement(vector<int> &a)
{
    int n = a.size();
    vector<int> result(n);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= a[i])
            s.pop();

        if (s.empty())
            result[i] = -1;
        else
            result[i] = s.top();

        s.push(a[i]);
    }

    for (int i = 0; i < n; i++)
        cout << result[i] << " ";
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    printNextGreaterElement(a);
    return 0;
}