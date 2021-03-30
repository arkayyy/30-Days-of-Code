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

Node* addTwoLL(Node* first,Node* second)
{
    Node* current = first;
        Node *prev = NULL, *next = NULL;
        int c1=0,c2=0;
 //Reversing once
        while (current != NULL) {
            next = current->next;  // Store next
            current->next = prev;   // Reverse current node's pointer
            prev = current;   // Move pointers one position ahead.
            current = next;
            c1++;
        }
     first = prev;
     
     current = second;
    prev = NULL;
    next = NULL;
 //Reversing once
        while (current != NULL) {
            next = current->next;  // Store next
            current->next = prev;   // Reverse current node's pointer
            prev = current;   // Move pointers one position ahead.
            current = next;
            c2++;
        }
     second = prev;
    
    if(c2>=c1)
    {
    Node* curr1=first;
    Node* curr2=second;
    int carry=0;
    while(curr2!=NULL)
    {
        if(curr1->data+curr2->data >= 10)
        {
            curr2->data=(curr1->data+curr2->data)%10  + carry;
            carry=1;
            curr1=curr1->next;
            curr2=curr2->next;
            
        }
        else{
            curr2->data=(curr1->data+curr2->data)+carry;
            carry=0;
            curr1=curr1->next;
            curr2=curr2->next;
        }
    }

     current = second;
    prev = NULL;
    next = NULL;
 //Reversing once
        while (current != NULL) {
            next = current->next;  // Store next
            current->next = prev;   // Reverse current node's pointer
            prev = current;   // Move pointers one position ahead.
            current = next;
        }
     second = prev;

    return second;}

    else if(c1>c2)

    {

    Node* curr2=first;
    Node* curr1=second;
    int carry=0;
    while(curr2!=NULL)
    {
        if(curr1->data+curr2->data >= 10)
        {
            curr2->data=(curr1->data+curr2->data)%10  + carry;
            carry=1;
            curr1=curr1->next;
            curr2=curr2->next;
            
        }
        else
        {
            curr2->data=(curr1->data+curr2->data)+carry;
            carry=0;
            curr1=curr1->next;
            curr2=curr2->next;
        }
    }

    current = first;
    prev = NULL;
    next = NULL;
 //Reversing once
        while (current != NULL) {
            next = current->next;  // Store next
            current->next = prev;   // Reverse current node's pointer
            prev = current;   // Move pointers one position ahead.
            current = next;
        }
    first = prev;

    return first;
    }

    return NULL;


}

int main(){
    int data;
    cin>>data;
    struct Node* pre=new Node(data);
    struct Node* first=pre;
    while(true)
    {cin>>data;
    struct Node* n=new Node(data);
        if(data==0){pre->next=NULL;break;}
        else{
            
            pre->next=n;
            pre=n;

        }
    }

    cin>>data;
    struct Node* pre1=new Node(data);
    struct Node* second=pre1;

    while(true)
    {cin>>data;
    struct Node* n=new Node(data);
        if(data==0){pre1->next=NULL;break;}
        else{
            
            pre1->next=n;
            pre1=n;

        }
    }
    



    Node* outputHead= addTwoLL(first,second);
    print(outputHead);


}

