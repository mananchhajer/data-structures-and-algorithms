#include <bits/stdc++.h>
using namespace std; 

struct node 
{ 
	int data; 
	struct node* left; 
	struct node* right; 
}; 

int search(int arr[], int strt, int end, int value); 
node* newNode(int data); 

node* buildTree(int in[], int pre[], int inStrt, int inEnd) 
{ 
	static int preIndex = 0; 

	if (inStrt > inEnd) 
		return NULL; 

	node* tNode = newNode(pre[preIndex++]); 
	if (inStrt == inEnd) 
		return tNode; 

	int inIndex = search(in, inStrt, inEnd, tNode->data); 

	tNode->left = buildTree(in, pre, inStrt, inIndex - 1); 
	tNode->right = buildTree(in, pre, inIndex + 1, inEnd); 

	return tNode; 
} 

int search(int arr[], int strt, int end, int value) 
{ 
	int i; 
	for (i = strt; i <= end; i++) 
	{ 
		if (arr[i] == value) 
			return i; 
	} 
} 

node* newNode(int data) 
{ 
	node* Node = new node(); 
	Node->data = data; 
	Node->left = NULL; 
	Node->right = NULL; 

	return (Node); 
} 

void printInorder(node* node) 
{ 
	if (node == NULL) 
		return; 

	printInorder(node->left); 

	cout<<node->data<<" "; 

	printInorder(node->right); 
}
int main() 
{ 
	int in[] = { 1,2,3,4,5,6,7 }; 
	int pre[] = { 5,3,1,2,4,6,7 }; 
	int len = sizeof(in) / sizeof(in[0]); 
	node* root = buildTree(in, pre, 0, len - 1); 

	cout << "Inorder traversal of the constructed tree is \n"; 
	printInorder(root);
	cout<<endl;

	return 0;
}