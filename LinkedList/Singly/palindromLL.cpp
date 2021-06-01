#include<bits/stdc++.h>
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

bool isPal(node* &head){

    node* temp = head;

    stack <int> s;

    while(temp != NULL){

        s.push(temp->data);
        temp= temp->next;
    }
    node* it = head;
    while(it != NULL){

        int i = s.top();
        s.pop();

        if( it->data != i){
            return false;
        }
        it = it->next;
    }
    return true;
}

int main(){

    node* head = NULL;

    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,3);
    InsertAtTail(head,2);
    InsertAtTail(head,1);
    cout<< isPal(head)<< endl;
}