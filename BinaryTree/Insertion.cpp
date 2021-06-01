#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

Node* Insertion(){
    Node* node = NULL;
    cout<< "Enter Data: "<<endl;
    int data;
    cin>>data;
    if(data == -1) return NULL;
    node = new Node(data);

    cout<< "Enter left for: " << data << endl;
    node->left = Insertion();
    cout<< "Enter right for " << data << endl;
    node->right = Insertion();

    return node;
}
void printInorder(struct Node* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node->left);

	/* then print the data of node */
	cout << node->data << " ";

	/* now recur on right child */
	printInorder(node->right);
}
int main(){

    struct Node* root = Insertion();
    printInorder(root);
    return 0;
}