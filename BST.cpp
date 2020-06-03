#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* right;
	Node* left;
};
Node* newnode(int data)
{
	Node* newnode=new Node();
	newnode->data=data;
	newnode->left=newnode->right=NULL;
}

Node* insert(Node* root,int data)
{
	if (root==NULL)
	{
		root=newnode(data);
		printf("inserted\n");
		return root;
	}
	else{
		if(data<=root->data)
		{
			root->left=insert(root->left,data);
			printf("left");
		}
		else
			root->right=insert(root->right,data);
			printf("right");
	}
	return root;
}
bool find(Node* root,int data){
	if (root==NULL) return false;
	else if (root->data==data) return true;
	else if(data<=root->data) return find(root->left,data);
	else return find(root->right,data);
}

Node* root;
int main()
{
	root=NULL;
	root=insert(root,2);
	root=insert(root,4);
	root=insert(root,1);
	root=insert(root,56);
	bool res=find(root,56);
	cout<<res;
}
