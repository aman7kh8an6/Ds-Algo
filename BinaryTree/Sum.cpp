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
int sum(Node* root, int s = 0){
    static int ans = 0;
    if(!root) return 0;
    s = s*10 + root->data;

    if(!root->left && !root->right) ans +=s;
    sum(root->left,s);
    sum(root->right,s);

    return  ans ;
}
void Inorder(Node* root){
    if(!root) return;
    Inorder(root->left);
    cout<< root->data << " ";
    Inorder(root->right);
}
int main(){
    struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
    root->right->right = new Node(7);
    root->right->left = new Node(6);
    // preorder(root);
    cout<< sum(root,0)<<endl;
    // preorder(root);
    return 0;
}