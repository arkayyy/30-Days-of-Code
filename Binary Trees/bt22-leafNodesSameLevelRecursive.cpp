#include <bits/stdc++.h>
using namespace std;

class BT
{
    public: int data;
    BT* left, *right;

    BT(int value)
    {
        this->data=value;
        this->left=this->right=NULL;
    }
};

bool checkLeafSame(BT* root