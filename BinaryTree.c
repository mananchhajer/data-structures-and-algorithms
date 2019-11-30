#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
struct node{
    int data;
    struct node*left, *right;
};
struct node* Insert(struct node* T,int value){
    if(T==NULL){
        T=(struct node*)malloc(sizeof(struct node));
        T->data=value;
        T->left=T->right=NULL;
    }
    else if(T->data > value){
        T->left=Insert(T->left,value);
    }
    else{
        T->right=Insert(T->right,value);
    }
    return T;
}
void printTree(struct node* T){
    if(T!=NULL){
        printTree(T->left);
        printf("%d ",T->data);
        printTree(T->right);
    }
}
int max(int a,int b){
    return (a>b)?a:b;
}
int height(struct node* T){
    if(T==NULL){
        return 0;
    }
    else{
        return 1+max(height(T->left),height(T->right));
    }
}
struct node* FindMIN(struct node* T){
    if(T==NULL){
        printf("Empty Tree\n");
    }
    else if(T->left==NULL){
        return T;
    }
    FindMIN(T->left);
}
struct node* FindMax(struct node* T){
    if(T==NULL){
        printf("Empty Tree\n");
    }
    else if(T->right==NULL){
        return T;
    }
    FindMax(T->right);
}
struct node* Delete(struct node* T,int value){
    if(T==NULL){
        return T;
    }
    else if(T->data > value){
        T->left= Delete(T->left,value);
    }
    else if(T->data < value){
        T->right= Delete(T->right,value);
    }
    else{
        if(T->left==NULL && T->right==NULL){
            free(T);
            T=NULL;
        }
        else if(T->left==NULL){
            struct node* temp=T;
            T=T->right;
            free(temp);
        }
        else if(T->right==NULL){
            struct node* temp=T;
            T=T->left;
            free(temp);
        }
        else{
            struct node* temp=FindMIN(T);
            T->data=temp->data;
            Delete(T->right,temp->data);
        }
    }
    return T;
}
int main(){
    struct node* Tree=NULL;
    Tree=Insert(Tree,9);  
    Tree=Insert(Tree,16);  
    Tree=Insert(Tree,4);  
    Tree=Insert(Tree,2);  
    Tree=Insert(Tree,6);  
    Tree=Insert(Tree,13);    
    printf("Height is %d \n",height(Tree));
    printTree(Tree);
    printf("\n Min is : %d",FindMIN(Tree)->data);
    printf("\nMax is : %d \n",FindMax(Tree)->data);
    Tree=Delete(Tree,6);
    printf("After deletion : \n");
    printTree(Tree);
}