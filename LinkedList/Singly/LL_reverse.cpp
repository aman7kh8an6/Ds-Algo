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

void Insertion(node* &head, int val ){

    node* n = new node(val);

    if (head == NULL){

        head = n;
    }

    node* temp = head;

    while(temp -> next != NULL){
        temp = temp->next;
    }

    temp->next = n;
    n->next = NULL;
}

node* reverseLL(node* &head){

    node* prev = NULL;
    node* curr = head;
    node* nextptr;

    while( curr != NULL){

        nextptr = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nextptr;
    }

    return prev;
}

node* reverseK(node* &head,int k){

    node* prev = NULL;
    node* curr = head;
    node* nextptr;
    int count = 0;
    while(curr!=NULL && count < k){
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
        count++;
    }
    if(nextptr!=NULL){
        head->next = reverseK(nextptr,k);
    }
    return prev;
}

void display(node* head){

    node* temp = head;

    while(temp != NULL){

        cout<< temp->data << "->";
        temp = temp->next;
    }cout<<"NULL"<<endl;
}

int main(){

    node* head = NULL;

    Insertion(head,1);
    Insertion(head,2);
    Insertion(head,3);
    Insertion(head,4);
    Insertion(head,5);
    display(head);
    int k = 2;
    node* afterReverK = reverseK(head,k);
    display(afterReverK);
    node* newHead = reverseLL(head);
    display(newHead);
}