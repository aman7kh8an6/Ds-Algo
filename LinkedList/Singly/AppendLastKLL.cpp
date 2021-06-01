#include<iostream>
using namespace std;

class node{

public:
    int data;
    node* next;

    
    node(int val){
        data = val;
        next = NULL;
    }
};

void InsertAtTail(node* &head, int val){

    node* n = new node(val);

    if(head == NULL){

        head = n;
        return;
    }

    node* temp = head;

    while(temp->next != NULL){

        temp = temp->next;
    }
    temp->next = n;

}

void display(node* head){

    node* temp = head;

    while(temp != NULL){

        cout<<temp->data<<"->";
        temp = temp->next;
    }cout<<"NULL"<<endl;

}

node* ApLastK(node* &head, int k){

    node* tail;
    node* newTail;
    node* newHead;
    node* temp = head;

    int count = 1;
    while(temp->next != NULL){

        if (count == k){

            newTail = temp;
            newHead = temp->next;
            
        }
        count++;
        temp=temp->next;
    }

    newTail->next = NULL;
    temp->next = head;

    return newHead;
}

int main(){

    node* head = NULL;

    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,4);
    InsertAtTail(head,5);
    InsertAtTail(head,6);
    display(head);
    node* newHead = ApLastK(head,3);
    display(newHead);
    
}