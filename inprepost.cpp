#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
};
Node* root;
void preorder(Node* root)
{
	if(root==NULL)  return;
	printf("%d",root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder(Node* root)
{
	if(root==NULL)  return;
	preorder(root->left);
	printf("%d",root->data);
	preorder(root->right);
}
void postorder(Node* root)
{
	if(root==NULL)  return;
	preorder(root->left);
	preorder(root->right);
	printf("%d",root->data);
}
Node* insert(Node* root,int data)
{
	if(root==NULL)
	{
		Node* temp=new Node();
		temp->data=data;
		temp->left=NULL;
		temp->right=NULL;
		root=temp;
		return root;
	}
	else{
		if(data>root->data){
			root->right=insert(root->right,data);
			return root;
		}
		else
		{
			root->left=insert(root->left,data);
			return root;
		}
	}
}
int main()
{
	root=NULL;
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		int data;
		cin>>data;
		root=insert(root,data);
	}
	cout<<"preorder is:"; preorder(root);
	cout<<"inorder is:"; inorder(root);
	cout<<"postorder is:"; postorder(root);
}
