#include <bits/stdc++.h>
using namespace std;

class BT
{
    public:
    int data;
    BT* left,*right;

    BT(int value)
    {
        this->data=value;
        this->left=this->right=NULL;
    }
};

vector<int> topViewLevelOrderIterative(BT* root)
{vector<int> left;
vector<int> right;
    queue<pair<BT*,int>> q;
    q.push(make_pair(root,0));
    int l=0,r=0,hd=0;                  // l - maximum left horizontal distance    r-maximum right horizontal distance
BT* t;
    while(!q.empty())
    {   t=q.front().first;
        hd=q.front().second;    // current node's horizontal distance
        q.pop();
        if(hd<l)
            {
                l=hd;
                left.push_back(t->data);
            }
        else if(hd>r)
            {
                r=hd;
                right.push_back(t->data);
            }
        if(t->left)
            q.push(make_pair(t->left,hd-1));
        if(t->right)
            q.push(make_pair(t->right,hd+1));
    }
    reverse(left.begin(),left.end());
    left.insert(left.end(),root->data);
    left.insert(left.end(),right.begin(),right.end());
    return left;

}

int main()
{
    BT* root=new BT(1);
    root->left=new BT(2);
    root->right=new BT(3);
    root->left->left=new BT(4);
    root->left->right=new BT(5);
    vector<int>v=topViewLevelOrderIterative(root);

    int i=0;
    for(auto i:v)
    {
        cout<<i<<" ";
    }
    return 0;
}