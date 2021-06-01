// #include<iostream>
// #include<vector>
// using namespace std;

// class ListNode{

//     public:
//         int val;
//         ListNode* next;

//         ListNode(int data){
//             val = data;
//             next = NULL;
//         }
// };
 

// ListNode* mergeKLists(vector<ListNode*>& lists) {
        
//     ListNode* dumm = new ListNode(-1);
//     ListNode* p1 = dumm;
//     int len = lists.size();
//     for(int i = 1; i <= len; i++){
            
//         ListNode* head_0 = lists[0];
//         ListNode* head_i = lists[i];
            
//         while(head_0 != NULL && head_i != NULL){
                
//             if( head_0 ->val < head_i->val){
//                 p1->next = head_0;
//                 head_0 = head_0->next;
//             }else{
//                 p1->next = head_i;
//                 head_i = head_i->next;
//             }
//             p1 = p1->next;
//         }
//         while(head_0 != NULL){
//             p1->next = head_0;
//             p1 = p1->next;
//             head_0 = head_0->next;
//         }
//         while(head_i != NULL){
//             p1->next = head_i;
//             p1 = p1->next;
//             head_i = head_i->next;
//         }
//     }
//     return dumm->next;
// }
// void printList(ListNode* node)
// {
//     while (node != NULL) {
//         printf("%d ", node->data);
//         node = node->next;
//     }
// }


// int main(){

//     ListNode* arr[3];

//     arr[0] = ListNode(1);
//     arr[0]->next = ListNode(3);
//     arr[0]->next = ListNode(5);
//     arr[0]->next = ListNode(7);

//     arr[1]->next = ListNode(2);
//     arr[1]->next = ListNode(4);
//     arr[1]->next = ListNode(6);
//     arr[1]->next = ListNode(8);

//     arr[2]->next = ListNode(0);
//     arr[2]->next = ListNode(9);
//     arr[2]->next = ListNode(10);
//     arr[2]->next = ListNode(11);

//     ListNode* head = mergeKLists(arr);

//     printList(head);
    
// }
// C++ program to merge k sorted
// arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
	int data;
	Node* next;
};

/* Function to print nodes in
a given linked list */
void printList(Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}
Node* mergeKLists(Node* lists[], int last) {
        
    Node* dumm = new Node(-1);
    Node* p1 = dumm;

    for(int i = 1; i <= last; i++){
            
        Node* head_0 = lists[0];
        Node* head_i = lists[i];
            
        while(head_0 != NULL && head_i != NULL){
                
            if( head_0->data < head_i->data){
                p1->next = head_0;
                head_0 = head_0->next;
            }else{
                p1->next = head_i;
                head_i = head_i->next;
            }
            p1 = p1->next;
        }
        while(head_0 != NULL){
            p1->next = head_0;
            p1 = p1->next;
            head_0 = head_0->next;
        }
        while(head_i != NULL){
            p1->next = head_i;
            p1 = p1->next;
            head_i = head_i->next;
        }
    }
    return dumm->next;
}
// The main function that
// takes an array of lists
// arr[0..last] and generates
// the sorted output


// Utility function to create a new node.
Node* newNode(int data)
{
	struct Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

// Driver program to test
// above functions
int main()
{
	// Number of linked lists
	int k = 3;

	// Number of elements in each list
	int n = 4;

	// an array of pointers storing the
	// head nodes of the linked lists
	Node* arr[k];

	arr[0] = newNode(1);
	arr[0]->next = newNode(3);
	arr[0]->next->next = newNode(5);
	arr[0]->next->next->next = newNode(7);

	arr[1] = newNode(2);
	arr[1]->next = newNode(4);
	arr[1]->next->next = newNode(6);
	arr[1]->next->next->next = newNode(8);

	arr[2] = newNode(0);
	arr[2]->next = newNode(9);
	arr[2]->next->next = newNode(10);
	arr[2]->next->next->next = newNode(11);

	// Merge all lists
	Node* head = mergeKLists(arr, k - 1);

	printList(head);

	return 0;
}
