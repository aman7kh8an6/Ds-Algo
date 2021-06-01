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

int countOccurence(node* &head, int key){

    node* temp = head;
    int count = 0;
    while(temp != NULL){

        if (temp->data == key){

            count++;
        }
        temp = temp->next;
    }
    return count;
}

void InsertAtTail(node* &head, int val){

    node* n = new node(val);

    if (head == NULL){

        head = n;
    }
    if (head->next == NULL){
        head -> next = n;
        n -> next =NULL;
    }
    node* temp = head;

    while(temp->next != NULL){

        temp = temp->next;
    }
    temp->next = n;
    n->next = NULL;
}
void display(node* &head){

    node* temp = head;
    while(temp!=NULL){

        cout<< temp->data << "->";
        temp = temp->next;
    }cout<<"NULL"<<endl;
}

int main(){

    node* head = NULL;
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,6);
    display(head);
    cout<< countOccurence(head,3) << endl;
    cout<< countOccurence(head,2) << endl;
    cout<< countOccurence(head,1) << endl;
}