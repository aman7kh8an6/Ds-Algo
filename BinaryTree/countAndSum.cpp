#include <iostream>
#include<queue>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

int count(Node* root){
    if(root == NULL) return 0;

    return count(root->left) + count(root->right) + 1;
}

int sum(Node* root){
    if(root == NULL) return 0;

    return sum(root->left) + sum(root->right) + root->data;
}

int main()
{
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
    root->right->right = new Node(7);
    root->right->left = new Node(6);

    int c = count(root);
    cout<< "Total nodes in a tree -> "<< count(root)<<endl;
    int s = sum(root);
    cout<< "Total sum of the nodes in a tree -> "<< sum(root)<<endl;
    return 0;
}