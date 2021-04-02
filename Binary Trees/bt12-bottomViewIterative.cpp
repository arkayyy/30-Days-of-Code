// 

#include <bits/stdc++.h>
using namespace std;

class BT
{
    public:
    int data;
    BT* left, *right;

    BT(int value)
    {
        this->data=value;
        this->left=this->right=NULL;
    }
};

vector<int> bottomViewIterative(BT* root)
{vector<int> v;
    queue<pair<BT*, int>> q;
    map<int,int> m;

    q.push(make_pair(root,0));

    while(!q.empty())
    {
        BT* t=q.front().first;
        int hd=q.front().second;
        q.pop();
        m[hd]=t->data;

        if(t->left)
            q.push(make_pair(t->left,hd-1));
        if(t->right)
            q.push(make_pair(t->right,hd+1));
    }
    for(auto i=m.begin();i!=m.end();i++)
    {
        v.push_back(i->second);
    }

    return v;

}

int main()
{
    BT* root=new BT(1);
    root->left=new BT(2);
    root->right=new BT(3);
    root->left->left=new BT(4);
    root->left->right=new BT(5);
    vector<int> v= bottomViewIterative(root);
    int i=0;
    for(auto i:v)
    {
        cout<< i<<" ";
    }
    return 0;
}