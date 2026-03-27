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
    if (nodes[0] == "N")
        return NULL;

    Node *root = new Node(stoi(nodes[0]));
    queue<Node *> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < nodes.size())
    {
        Node *curr = q.front();
        q.pop();

        if (nodes[i] != "N")
        {
            curr->left = new Node(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        if (i >= nodes.size())
            break;

        if (nodes[i] != "N")
        {
            curr->right = new Node(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

bool isLeaf(Node *node)
{
    return !node->left && !node->right;
}

void addLeftBoundary(Node *root, vector<int> &res)
{
    Node *cur = root->left;
    while (cur)
    {
        if (!isLeaf(cur))
            res.push_back(cur->data);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

void addLeaves(Node *root, vector<int> &res)
{
    if (!root)
        return;
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    addLeaves(root->left, res);
    addLeaves(root->right, res);
}

void addRightBoundary(Node *root, vector<int> &res)
{
    Node *cur = root->right;
    vector<int> temp;

    while (cur)
    {
        if (!isLeaf(cur))
            temp.push_back(cur->data);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }

    reverse(temp.begin(), temp.end());
    for (int x : temp)
        res.push_back(x);
}

vector<int> boundaryTraversal(Node *root)
{
    vector<int> res;
    if (!root)
        return res;

    if (!isLeaf(root))
        res.push_back(root->data);

    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    return res;
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

    vector<int> res = boundaryTraversal(root);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ", ";
    }

    return 0;
}