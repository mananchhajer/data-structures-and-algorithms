#include<stdio.h>
#include<stdlib.h>
struct  node{
	int item;
	struct node* next;
};
struct node* root;
struct node* InsertNodeAtHead(struct node* root,int value){
	struct node* temp=(struct node*)malloc(sizeof(struct node*));
	temp->item=value;
	temp->next=NULL;
	if(root!=NULL){
      temp->next=root;
	}
	root=temp;
	return root;
}
struct node* InsertNodeAtTail(struct node* leaf,int value){
	struct node* temp=(struct node*)malloc(sizeof(struct node*));
	temp->item=value;
	temp->next=NULL;
	if(leaf!=NULL){
		leaf->next=temp;
	}
	leaf=temp;
	return leaf;
}
int main(){
	struct node* head=(struct node*)malloc(sizeof(struct node*));
head=InsertNodeAtHead(head,2);

head=InsertNodeAtHead(head,3);
head=InsertNodeAtHead(head,4);
for(int i=0;i<3;i++){
	printf("%d \n",head->item);
	head=head->next;
}
struct node* tail=(struct node*)malloc(sizeof(struct node*));
struct node* t=(struct node*)malloc(sizeof(struct node*));

tail=InsertNodeAtTail(tail,22);
t=tail;
tail=InsertNodeAtTail(tail,23);

tail=InsertNodeAtTail(tail,24);

for(int i=0;i<3;i++){
	printf("%d \n",t->item);
	t=t->next;
}
}
