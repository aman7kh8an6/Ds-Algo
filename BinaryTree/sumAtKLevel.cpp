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

int sumAtLevel(Node* root, int k){
    if( root == NULL) return -1; 
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int s = 0;
    int level = 0;
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if( temp != NULL){
            if( level == k){
                s = s + temp->data;
            }
            // cout<< temp->data<<" ";
            if( temp->left) q.push(temp->left);
            if( temp->right) q.push(temp->right);
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return s;
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

    cout << "\nLevelorder traversal of binary tree is \n";
	cout<< sumAtLevel(root,2);

    return 0;
}