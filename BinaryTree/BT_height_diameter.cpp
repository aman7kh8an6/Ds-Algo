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

int height(Node* root){
    if( root == NULL) return 0;
    int l_height = height(root->left);
    int r_height = height(root->right);

    return max(l_height, r_height) + 1;
}

int diameter(Node* root){
	if(root == NULL) return 0;
	int lh = height(root->left);
	int rh = height(root->right);
	int currDiameter = lh+rh + 1;

	int ld = diameter(root->left);
	int rd = diameter(root->right);

	return max( currDiameter, max(ld,rd));
}

int calDiameter(Node* root, int* height){
	if(root == NULL){
		*height = 0;
		return 0;
	}
	int lh = 0, rh = 0;
	int ld = calDiameter(root->left, &lh);
	int rd = calDiameter(root->right, &rh);
	int currDiameter = lh+rh+1;
	*height = max(lh,rh)+1;

	return max(currDiameter, max(ld,rd));
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

    cout<< height(root) <<endl;
	cout<< diameter(root) << endl;
	int height = 0;
	cout<< calDiameter(root,&height) << endl;
    return 0;
}