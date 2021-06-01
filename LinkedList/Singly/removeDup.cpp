#include<bits/stdc++.h>
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

void Insertion(node* &head, int val){
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
    n->next = NULL;
}

void display(node* &head){

    node* temp = head;

    while(temp != NULL){

        cout<< temp->data << "->";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}

void removeDup(node* &head){

    node* temp = head;
    unordered_set<int> seen;

    while(temp->next!=NULL){

        if(seen.find(temp->next->data) != seen.end()){
            temp = temp->next->next;
            delete temp->next;
        }
        else{
            seen.insert(temp->data);
            temp = temp->next;
        }
    }
    
}
int main(){

    node* head = NULL;

    Insertion(head,3);
    Insertion(head,2);
    Insertion(head,3);
    Insertion(head,2);
    Insertion(head,9);
    display(head);
    removeDup(head);
    display(head);
}