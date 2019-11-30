#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10
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
    struct node* temp;
    for(int i=0;i<G->totalnodes;i++){
         temp=G->adjlist[i];
          while(temp!=NULL){
              printf("%d ",temp->data);
              temp=temp->next;
          }
          printf("\n");
    }
}
/*void checkDFS(struct graph* G,int i,int dfsindex, bool visited[],int dfsArray[]){
    visited[i]=1;
    dfsArray[dfsindex]=i;
    dfsindex++;
    struct node* temp=G->adjlist[i];
    while(temp!=NULL){
        if(!visited[temp->data]){
            checkDFS(G,temp->data,dfsindex,visited,dfsArray);
        }
        temp=temp->next;
    }    
}
int* DFS(struct graph* G,int u){
    int dfsindex=0;
    int* dfsArray=(int*)malloc(G->totalnodes*sizeof(int));
    bool* visited=(bool*)malloc(G->totalnodes*sizeof(bool));
    for(int i=0;i<G->totalnodes;i++){
        visited[i]=0;
    }
    for(int i=0;i<G->totalnodes;i++){
        if(!visited[i]){
            checkDFS(G,i,dfsindex,visited,dfsArray);
        }
    }
    return dfsArray;
}*/
bool visited[MAX];

void DFS(struct graph* G,int i){
    struct node* temp;
    printf("%d ",i);
    visited[i]=1;
    temp=G->adjlist[i];
    while(temp!=NULL){
        printf("While\n");
        i=G->adjlist[i]->data;
        if(!visited[i]){
            printf("%d in DFS",i);
            DFS(G,i);
        }
        temp=temp->next;
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
    for(int i=0;i<MAX;i++){
    visited[i]=0;
}
    DFS(Graph,1);
}
