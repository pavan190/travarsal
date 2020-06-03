#include<iostream>
#include<queue>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
};

void levelorder(Node* root){
	if(root==NULL) return;
	queue<Node*> Q;
	Q.push(root);
	while(!Q.empty()){
		Node* current=Q.front();
			Q.pop();
		cout<<current->data<<" ";
		if(current->left!=NULL)
			Q.push(current->left);
		if(current->right!=NULL) 
			Q.push(current->right);
	
	}
}

Node* insert(Node* root,int data)
{
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else{
		if(data>root->data){
			root=insert(root->right,data);
			return root;
		}
		else{
			root=insert(root->left,data);
			return root;
		}
	}
}

Node* root;
int main()
{
	root=NULL;
	int i,n;
	cin>>n;
	for(i=0;i<n;i++)
	{
		int value;
		cin>>value;
		root=insert(root,value);
	}
	levelorder(root);
}
