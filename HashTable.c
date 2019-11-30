#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node* next;
};
struct node* InsertInList(struct node* head,int value){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    struct node* temp1;
    temp->data=value;
    temp->next=NULL;
    if(head==NULL){
        return temp;
    }
    else{
        temp1=head;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
    return head;
}
struct hashtable{
    int size;
    struct node ** table;
};
struct hashtable* createHashTable(int size){
    struct hashtable* h=(struct hashtable*)malloc(sizeof(struct hashtable));
    h->size=size;
    h->table=(struct node**)malloc(size*sizeof(struct node*));
    for(int i=0;i<size;i++){
        h->table[i]=NULL;
    }
    return h;
}
struct hashtable* InsertInHash(struct hashtable* h,int value){
    int index=value%(h->size);
    h->table[index]=InsertInList(h->table[index],value);
    return h;
}
void printHash(struct hashtable * h){
    for(int i=0;i<h->size;i++){
        while(h->table[i]!=NULL){
            printf("%d ",h->table[i]->data);
            h->table[i]=h->table[i]->next;
        }
        printf("\n");
    }
}
int main(){
    int size,n,temp;
    scanf("%d",&size);
    struct hashtable* H=createHashTable(size);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        H=InsertInHash(H,temp);
    }
    printHash(H);
}