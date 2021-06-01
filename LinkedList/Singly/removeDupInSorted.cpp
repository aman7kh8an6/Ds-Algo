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
    node* it = head;
    while(temp->next != NULL){

        if(temp->data == temp->next->data){

            while(it->next != NULL && it->next->data == it->data){
                it= it->next;
            }

            temp->next = it->next;
        }
        else{
            temp=temp->next;
            it = it->next;
        }
    }
}

int main(){

    node* head = NULL;

    Insertion(head,3);
    Insertion(head,3);
    Insertion(head,2);
    Insertion(head,2);
    Insertion(head,2);
    display(head);
    removeDup(head);
    display(head);
}