#include<bits/stdc++.h>
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

void topViewIterative(BT* root)
{
    if(!root)
        return;
    queue<pair<BT*,int>> q; 
    map<int, int> m;   
    q.push(make_pair(root,0));

    cout<<"The top view of tree is: \n";

    while(!q.empty())
    {   BT* t=q.front().first;
        int hd=q.front().second;
        q.pop();

        if(m.find(hd)==m.end())
            m[hd]=t->data;
        
        if(t->left)
            q.push(make_pair(t->left,hd-1));
        if(t->right)
            q.push(make_pair(t->right,hd+1));

        // q.pop();
        // t=q.front();
    }
    
    for(auto i=m.begin();i!=m.end();i++)
        cout<<i->second<<" ";
}

int main()
{
    BT* root=new BT(1);
    root->left=new BT(2);
    root->right=new BT(3);
    root->left->left=new BT(4);
    root->left->right=new BT(5);
    topViewIterative(root);
    
    return 0;
}