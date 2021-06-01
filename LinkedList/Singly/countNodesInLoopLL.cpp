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

void makeCycle(node* &head,int pos){

    node* temp = head;
    node* startNode;
    int count = 1;
    while(temp->next != NULL){

        if(count == pos){
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

node* detectCycle(node* &head){

    node* slow = head;
    node* fast = head;

    while(fast != NULL && fast->next != NULL){

        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast){

            return slow;
            break;
        }
    }
}
int countNodesInLoop(node* head){

    node* pos = detectCycle(head);
    node* fast = detectCycle(head);
    fast = fast->next;
    int count=1;
    while(fast != pos){
        fast=fast->next;
        count++;
    }
    return count;
}

void display(node* head){

    node* temp = head;

    while(temp != NULL){

        cout<<temp->data<<"->";
        temp = temp->next;
    }cout<<"NULL"<<endl;

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
    makeCycle(head,1);
    cout<< countNodesInLoop(head)<<endl;

}