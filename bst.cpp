#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data) 
{ 
    struct node* node = new struct node; 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
    return(node); 
}

node* insert(node* root, int data) 
{ 
    node* newnode = newNode(data); 
    node* x = root; 
    node* y = NULL; 
  
    while (x != NULL) 
    { 
        y = x; 
        if (data < x->data) 
            x = x->left; 
        else
            x = x->right; 
    } 
    if (y == NULL)
    	y = newnode; 
    else if (data < y->data) 
        y->left = newnode; 
    else
        y->right = newnode; 
    return y; 
} 

void Inorder(node* root) 
{ 
    if (root == NULL) 
        return; 
    else
    { 
        Inorder(root->left); 
        cout << root->data << " "; 
        Inorder(root->right); 
    } 
}

void Preorder(node* root) 
{ 
    if (root == NULL) 
        return; 
    else
    { 
        cout << root->data << " "; 
        Preorder(root->left); 
        Preorder(root->right); 
    } 
}

void Postorder(node* root) 
{ 
    if (root == NULL) 
        return; 
    else
    { 
        cout << root->data << " "; 
        Postorder(root->right);
        Postorder(root->left); 
    }
}

void printGivenLevel(node* root, int level);  
int height(node* node);  
node* newNode(int data);  


void printLevelOrder(node* root)  
{  
    int h = height(root);  
    int i;  
    for (i = 1; i <= h; i++)  
        printGivenLevel(root, i);  
}  

void printGivenLevel(node* root, int level)  
{  
    if (root == NULL)  
        return;  
    if (level == 1)  
        cout << root->data << " ";  
    else if (level > 1)  
    {  
        printGivenLevel(root->left, level-1);  
        printGivenLevel(root->right, level-1);  
    }  
}  

int height(node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {
        int lheight = height(node->left);  
        int rheight = height(node->right);  
  
        if (lheight > rheight)  
            return(lheight + 1);  
        else
        	return(rheight + 1);  
    }  
}

int main()
{

    /*
            50  
          /    \  
         30    70  
        / \    /  \  
       20 40  60  80 
    */

	node* root = NULL; 
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60); 
    insert(root, 80);

    Inorder(root);
    cout<<endl;
    Preorder(root);
    cout<<endl;
    Postorder(root);
    cout<<endl;

    node* root1=NULL;
    root1 = insert(root1, 5);
    insert(root1, 3);
    insert(root1, 4);
    insert(root1, 6);
    insert(root1, 1);
    insert(root1, 7);
    insert(root1, 2);
    printLevelOrder(root1);
    cout<<endl;
    int h=height(root1);
    cout<<h<<endl;

	return 0;
}