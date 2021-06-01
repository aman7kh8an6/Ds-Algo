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
    }cout<<"NUlL"<<endl;

}

int middle(node* head){

    node* slow = head;
    node* fast = head;
    while( fast != NULL && fast->next != NULL){

        fast = fast->next->next;
        slow = slow->next;
    }

    return slow->data;
}

int main(){

    node* head = NULL;
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,5);
    InsertAtTail(head,3);
    
    display(head);
    cout<< middle(head) << endl;
}