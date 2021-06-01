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

node* reverse(node* &head){

    node* prev = NULL;
    node* curr = head;
    node* next;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int length(node* &head){

    node* temp = head;
    int c=0;
    while(temp!= NULL){

        c++;
        temp = temp->next;
    }
    return c;
}

node* addLL(node* first, node* second)
{
 
    // res is head node of the resultant list
    node* f = reverse(first);
    node* s = reverse(second);
    node* res = NULL;
    node *temp, *prev = NULL;
    int carry = 0, sum;
 
    // while both lists exist
    while (f != NULL
           || s != NULL) {
        // Calculate value of next
        // digit in resultant list.
        // The next digit is sum of
        // following things
        // (i) Carry
        // (ii) Next digit of first
        // list (if there is a next digit)
        // (ii) Next digit of second
        // list (if there is a next digit)
        sum = carry + (f ? f->data : 0)
              + (s ? s->data : 0);
 
        // update carry for next calulation
        carry = (sum >= 10) ? 1 : 0;
 
        // update sum if it is greater than 10
        sum = sum % 10;
 
        // Create a new node with sum as data
        temp = new node(sum);
 
        // if this is the first node then
        // set it as head of the resultant list
        if (res == NULL)
            res = temp;
 
        // If this is not the first
        // node then connect it to the rest.
        else
            prev->next = temp;
 
        // Set prev for next insertion
        prev = temp;
 
        // Move first and second
        // pointers to next nodes
        if (f)
            f = f->next;
        if (s)
            s = s->next;
    }
 
    if (carry > 0)
        temp->next = new node(carry);
 
    // return head of the resultant list
    node* ans = reverse(res);
    return ans;
}
int main(){

    node* result = NULL;
    node* head1 = NULL;
    node* head2 = NULL;

    Insertion(head1,1);
    Insertion(head1,0);
    display(head1);
    Insertion(head2,1);
    Insertion(head2,1);
    Insertion(head2,1);
    display(head2);
    result = addLL(head1,head2);
    display(result);
}