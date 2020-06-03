#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* right;
	Node* left;
};
Node* root;
Node* newnode(int value){
	Node* temp=new Node();
	temp->data=value;
	temp->left=temp->right=NULL;
}
Node* insert(Node* root,int value){
	if(root==NULL){
		root=newnode(value);
		return root;
	}
	else
	{
		if(value>root->data)
		{
			root->right=insert(root->right,value);
			return root;
		}
		else
		{
			root->left=insert(root->left,value);
			return root;
		}
	}
}
int findheight(Node* root)
{
	if(root==NULL)
	{
		return -1;
	}
	else
	{
		int lh=findheight(root->left);
		int rh=findheight(root->right);
	cout<<"left:"<<lh<<" and right:"<<rh;
		int max;
		if (lh>rh){
			max=lh;
		}
		else{
			max=rh;
		}
	cout<<"max:"<<max<<"\n";
		return max+1;
	}
}
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
	int h=findheight(root);
	cout<<"height is"<<h;
}
