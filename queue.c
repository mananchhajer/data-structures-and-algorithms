#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int items[10];
	int front,rear;
}queue;
int empty(queue* q){
	if(q->rear+ q->front +1 ==0){
		return 1;
	}
	else{
		return 0;
	}
}
int enqueue(queue* q,int value){
	if(q->rear<9){
	q->items[++q->rear]=value;
}
else{
	printf("overflow\n");
}
}
int dequeue(queue* q){
	if(!empty(q)){
		return q->items[q->front++];
	}
	else{
		printf("Empty");
	}
}
int main(){
	queue* q=(queue*)malloc(sizeof(queue));
	q->front=0;
	q->rear=-1;
	enqueue(q,23);
	enqueue(q,46);
	enqueue(q,69);
	printf("%d\n",dequeue(q) );
	printf("%d\n",dequeue(q) );
	printf("%d\n",dequeue(q) );

}