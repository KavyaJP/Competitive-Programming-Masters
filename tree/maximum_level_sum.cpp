#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(vector<int> &arr, int &i)
{
    if (i >= arr.size() || arr[i] == -1)
    {
        i++;
        return NULL;
    }

    Node *root = new Node(arr[i++]);
    root->left = buildTree(arr, i);
    root->right = buildTree(arr, i);

    return root;
}

int maxLevelSum(Node *root)
{
    if (!root)
        return 0;

    queue<Node *> q;
    q.push(root);

    int maxSum = INT_MIN;

    while (!q.empty())
    {
        int size = q.size();
        int levelSum = 0;

        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();

            levelSum += curr->data;

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }

        maxSum = max(maxSum, levelSum);
    }

    return maxSum;
}

int main()
{
    vector<int> arr;
    int x;

    while (cin >> x)
    {
        arr.push_back(x);
    }

    int i = 0;
    Node *root = buildTree(arr, i);

    cout << maxLevelSum(root);

    return 0;
}