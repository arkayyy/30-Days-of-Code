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

void BinaryTree2DoubleLinkedList(BT *root, BT **head)
{
    // Base case
    if (root == NULL) return;

    // Initialize previously visited node as NULL. This is
    // static so that the same value is accessible in all recursive
    // calls
    BT* prev = NULL;

    // Recursively convert left subtree
    BinaryTree2DoubleLinkedList(root->left, head);

    // Now convert this node
    if (prev == NULL)
        *head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;

    // Finally convert right subtree
    BinaryTree2DoubleLinkedList(root->right, head);
}

int main()
{
    
    BT* root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    // root->left->left=newNode(4);
    //root->left->right=newNode(5);
    BT** ltop;
    BT* top=BinaryTree2DoubleLinkedList(root,ltop);
    BT* curr=top;
    while(curr->right!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->right;
    }
    cout<<curr->data<<"\n";
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->left;
    }

    return 0;

}


