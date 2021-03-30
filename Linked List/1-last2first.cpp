#include <iostream>
#include <cstdio>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    Node(int data){this->data=data;}
};

void print(Node* root){
    while(root!=NULL)
    {
        cout<<root->data<<endl;
        root=root->next;
    }
}

Node* last2first(Node* root)
{if(root==NULL){cout<<"LL is empty!"<<endl;}
    struct Node* curr=root;
    while(curr!=NULL){
        if(curr->next->next==NULL){
            struct Node* temp=new Node(curr->next->data);
            temp->next=root;
            curr->next=NULL;
            root=temp;
            break;
        }
        else{curr=curr->next;}
    }

    return root;


}

int main(){
    int data;
    cin>>data;
    struct Node* pre=new Node(data);
    struct Node* head=pre;
    while(true)
    {cin>>data;
    struct Node* n=new Node(data);
        if(data==0){pre->next=NULL;break;}
        else{
            
            pre->next=n;
            pre=n;

        }
    }
    struct Node* indi= last2first(head);
    print(indi);

}

