//WITHOUT USING QUEUE, ONLY MAP USED

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

void fillMap(BT* root, int l, int d, map<int,pair<int,int>> &m)
{
    if(!root)
        return;

    if(m.find(d)==m.end())         // FOR BOTTOM VIEW eliminate this IF condition
        m[d]=make_pair(root->data,l);
    else if(m[d].second>l)
        m[d]=make_pair(root->data,l);

    fillMap(root->left,l+1,d-1,m);
    fillMap(root->right,l+1,d+1,m);
}

vector<int> topViewNoQueue(BT* root)
{vector<int> v;
    map<int,pair<int,int>> m;
    fillMap(root,0,0,m);
    for(auto i=m.begin();i!=m.end();i++)
        v.push_back(i->second.first);

    return v;
}

int main()
{
    BT* root=new BT(1);
    root->left=new BT(2);
    root->right=new BT(3);
    root->left->left=new BT(4);
    root->left->right=new BT(5);
    vector<int>v=topViewNoQueue(root);

    int i=0;
    for(auto i:v)
    {
        cout<<i<<" ";
    }
    return 0;
}