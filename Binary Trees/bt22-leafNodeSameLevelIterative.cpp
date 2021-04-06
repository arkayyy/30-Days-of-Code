#include<bits/stdc++.h>
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

bool checkLeafSame(BT* root)
{
    if(!root)
        return true;
    int leaflevel=INT_MAX;
    int level=0;

    queue<BT*> q;
    q.push(root);

    while(!q.empty())
    {
        int size=q.size();
        level+=1;

        while(size>0)
        {
            BT* t=q.front();
            q.pop();

            if(t->left)
            {q.push(t->left);
                if(!t->left->left && !t->left->right)
                    {
                        if(leaflevel==INT_MAX)
                            leaflevel=level;
                        else if(leaflevel!=level)
                            return false;

                    }
            }

            if(t->right)
            {q.push(t->right);
                if(!t->right->left && !t->right->right)
                    {
                        if(leaflevel==INT_MAX)
                            leaflevel=level;
                        else if(leaflevel!=level)
                            return false;

                    }
            }

            size-=1;
        }
    }
    return true;
}

int main()
{
    BT* root=new BT(1);
    root->left=new BT(2);
    root->right=new BT(3);
    //root->left->left=new BT(4);
    cout<<checkLeafSame(root);

    return 0;
}