#include<bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    node *left,*right;
};

node* newNode(int key)
{
    node* Node = new node();
    Node->key = key;
    Node->left = Node->right = NULL;
    return Node;
}

node* insert(node* root, int data)
{
    node* newnode = newNode(data);
    node* x = root;
    node* y = NULL;

    while (x != NULL)
    {
        y = x;
        if (data < x->key)
            x = x->left;
        else
            x = x->right;
    }
    if (y == NULL)
    	y = newnode;
    else if (data < y->key)
        y->left = newnode;
    else
        y->right = newnode;
    return y;
}

node* rRotate(node *x)
{
    node* y = x->left;
    x->left = y->right;
    y->right  = x;
    return y;
}

node* lRotate(node *x)
{
    node* y = x->right;
    x->right = y->left;
    y->left  = x;
    return y;
}

void Preorder(node* root)
{
    if (root == NULL)
        return;
    else
    {
        cout << root->key << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

node* splay(node* root, int key)
{
    if(root == NULL || root->key == key)
        return root;
    if(root->key > key)
    {
        if(root->left == NULL)
            return root;
        if(root->left->key > key)
        {
            root->left->left = splay(root->left->left,key);
            root = rRotate(root);
        }
        else if (root->left->key < key)
        {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL)
                root->left = lRotate(root->left);
        }
        return((root->left == NULL)?root:rRotate(root));
    }
    else if(root->key < key)
    {
        if(root->right == NULL)
            return root;
        if(root->right->key > key)
        {
            root->right->left = splay(root->right->left,key);
            if (root->right->left != NULL)
                root->right = rRotate(root->right);
        }
        else if(root->right->key < key)
        {
            root->right->right = splay(root->right->right,key);
            root = lRotate(root);
        }
        return((root->right == NULL)?root:lRotate(root));
    }
}

node *search(node *root, int key)
{
    return splay(root, key);
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
    Preorder(root);
    cout<<endl;
    root=search(root, 40);
    Preorder(root);
    cout<<endl;
    return 0;
}
