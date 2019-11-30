#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node* next;
};
struct graph{
    struct node ** adjlist;
    int totalnodes;
};
struct graph* createGraph(int nodes){
    struct graph* G=(struct graph*)malloc(sizeof(struct graph));
    G->totalnodes=nodes;
    G->adjlist=(struct node**)malloc(nodes*sizeof(struct node*));
    for(int i=0;i<G->totalnodes;i++){
        G->adjlist[i]=NULL;
    }
    return G;
}
struct node* InsertInList(struct node*head,int value){
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
struct graph* InsertInGraph(struct graph* G,int u,int v){
    G->adjlist[u]=InsertInList(G->adjlist[u],v);
    //If undirected then also perfrom the reverse insertion.
    return G;
}
void printGraph(struct graph* G){
    for(int i=0;i<G->totalnodes;i++){
          while(G->adjlist[i]!=NULL){
              printf("%d ",G->adjlist[i]->data);
              G->adjlist[i]=G->adjlist[i]->next;
          }
          printf("\n");
    }
}
int main(){
    struct graph* Graph;
    int nodes;
    int u,v;
    scanf("%d",&nodes);
    Graph=createGraph(nodes);
    int connections;
    scanf("%d",&connections);
    for(int i=0;i<connections;i++){
        scanf("%d %d",&u,&v);
        Graph=InsertInGraph(Graph,u,v);
    }
    printGraph(Graph);
}
