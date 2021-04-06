#include <bits/stdc++.h>
using namespace std;

class BT
{
public:
    int data;
    BT *left, *right;

    BT(int value)
    {
        this->data = value;
        this->left = this->right = NULL;
    }
};

BT *buildTreeUtil(int in[], int pre[], int inStrt, int inEnd, unordered_map<int, int> &mp)
{
    static int preOrderIndex = 0;
    if (inStrt > inEnd)
        return NULL;

    BT *t = new BT(pre[preOrderIndex++]);

    if (inStrt == inEnd)
        return t;

    int inIndex = mp[t->data];

    t->left = buildTreeUtil(in, pre, inStrt, inIndex - 1, mp);
    t->right = buildTreeUtil(in, pre, inIndex + 1, inEnd, mp);

    return t;
}

BT *buildTree(int in[], int pre[], int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[in[i]] = i;
    }
    return buildTreeUtil(in, pre, 0, n - 1, mp);
}

void inOrderPrint(BT *root)
{
    if (!root)
        return;

    inOrderPrint(root->left);
    cout << root->data << " ";
    inOrderPrint(root->right);
}
int main()
{
    int in[] = {3, 1, 4, 0, 5, 2};
    int pre[] = {0, 1, 3, 4, 2, 5};

    BT *root = buildTree(in, pre, 6);

    inOrderPrint(root);

    return 0;
}