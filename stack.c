#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct stack{
    int top;
    int* data;
};
struct stack* createStack(struct stack* s,int n){
    s->top=-1;
    s->data=(int*)malloc(n*sizeof(int));
    return s;
}
int push(struct stack* s,int value){
    return s->data[++s->top]=value;
}
void pop(struct stack* s){
    s->top--;
}
int Top(struct stack* s){
    return s->data[s->top];
}
bool empty(struct stack* s){
    return s->top==-1;
}

int main(){
    struct stack* s;
    int n;
    scanf("%d",&n);
    s=createStack(s,n);
    int temp;
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        push(s,temp);
    }
    for(int i=0;i<n;i++){
        printf("%d ",Top(s));
        pop(s);
    }
    printf("%d\n",empty(s));
}