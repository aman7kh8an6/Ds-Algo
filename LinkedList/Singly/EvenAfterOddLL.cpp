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

void evenAfterOdd(node* &head){

    node* odd = head;
    node* even = head->next;
    node* evenStart = even;

    while(even->next!=NULL && odd->next != NULL){

        odd->next = even->next;
        odd = odd->next;
        even ->next = odd->next;
        even = even->next; 
    }

    odd->next = evenStart;
    if(odd->next != NULL){
        even->next = NULL;
    }
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
    evenAfterOdd(head);
    display(head);
}