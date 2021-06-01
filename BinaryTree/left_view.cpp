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

vector<int> leftView(Node* root){
    if(!root) return {};
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    vector<int> v;
    v.push_back(root->data);
    while(!q.empty()){
        Node* temp1 = q.front();0
        q.pop();
        if(temp1 != NULL){
            if(temp1->left) q.push(temp1->left);
            if(temp1->right) q.push(temp1->right);
        }else if(!q.empty()){
            if(q.front()){
                Node* var = q.front();
                v.push_back(var->data);
            }
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
    v1 = leftView(root);
    for(int i = 0; i < v1.size(); i++){
        cout<< v1[i] << " ";
    }
    return 0;
}