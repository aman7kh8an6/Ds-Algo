#include <bits/stdc++.h>
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

vector<int> rightView(Node* root){
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    vector<int> v;
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        Node* temp1 = q.front();
        if( temp != NULL){
            if(temp1 == NULL){
                v.push_back(temp->data);
            }
            if( temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }else if(!q.empty()){
            q.push(NULL);
        }
    }
    return v;
}
int main()
{
	struct Node* root = new Node(1);
    vector<int> v1;
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->right->left = new Node(5);
    root->right->left->left = new Node(7);
    root->right->right = new Node(6);
    v1 = rightView(root);
    for(int i = 0; i < v1.size(); i++){
        cout<< v1[i] << " ";
    }
    return 0;
}