#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#define V 9
int minDist(int dist[],bool marked[]){ 
    int min=100;
    int min_index;
    for(int i=0;i<V;i++){
        if(!marked[i] && dist[i]<min){
            min=dist[i];
            min_index=i;
        }
    }
    return min_index;
}
void Djikstra(int graph[V][V],int src){
    int dist[V];
    bool marked[V];
    for(int i=0;i<V;i++){
        dist[i]=100;
        marked[i]=0;
    }
    dist[src]=0;
    for(int count=0;count<V-1;count++){
        int min_index=minDist(dist,marked);
        marked[min_index]=1;
        for(int i=0;i<V;i++){
            if(dist[min_index]+graph[min_index][i]<dist[i] && graph[min_index][i]){
                dist[i]=dist[min_index]+graph[min_index][i];
            }
        }
    }
    for(int i=0;i<V;i++){
        printf("Min dist from the source is : %d \n",dist[i]);
    }
}
int main(){

    int graph[V][V]={   { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    int src;
    scanf("%d",&src);
    Djikstra(graph,src);
}