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

Node *buildTree(vector<string> &nodes)
{
    if (nodes[0] == "null")
        return NULL;

    Node *root = new Node(stoi(nodes[0]));
    queue<Node *> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < nodes.size())
    {
        Node *curr = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != "null")
        {
            curr->left = new Node(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null")
        {
            curr->right = new Node(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int diameter = 0;

int height(Node *root)
{
    if (!root)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    diameter = max(diameter, left + right);

    return 1 + max(left, right);
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    string line;
    getline(cin, line);

    vector<string> nodes;
    string temp;

    for (char c : line)
    {
        if (c == ',' || c == ' ')
        {
            if (!temp.empty())
            {
                nodes.push_back(temp);
                temp.clear();
            }
        }
        else
        {
            temp += c;
        }
    }
    if (!temp.empty())
        nodes.push_back(temp);

    Node *root = buildTree(nodes);

    height(root);

    cout << diameter;

    return 0;
}