#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int top;
	int items[10]
}stack;
void push(stack *s, int val){
	s->items[++s->top]=val;
}
int empty(stack *s){
	if(s->top==-1)
		return 1;
	else
		return 0;
}
int pop(stack *s){
	if(!empty(s))
		return(s->items[s->top--]);
}
int Top(stack *s){
	return(s->items[s->top]);
}
int main()
{
	stack *s=(stack*)malloc(sizeof(stack));
	push(s,1);
	push(s,2);
	printf("%d\n",pop(s));
	printf("%d\n",pop(s));	

	return 0;
}
