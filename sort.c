#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void Merge(int A[],int l,int med,int r){
    int n1=med-l+1;
    int n2=r-med;
    int i,j,k;
    k=l;
    int Left[n1],Right[n2];
    //declare temp array for left and right;
    for(int i=0;i<n1;i++){
        Left[i]=A[l+i];
    }
    for(int j=0;j<n2;j++){
        Right[j]=A[med+1+j];
    }
    i=0;
    j=0;
    while(i<n1 && j<n2){
        if(Left[i]<=Right[j]){
            A[k]=Left[i];
            i++;
            k++;
        }
        else{
            A[k]=Right[j];
            j++;
            k++;
        }
    }
    while(i<n1){
            A[k]=Left[i];
            i++;
            k++;
        }
    while(j<n2){
            A[k]=Right[j];
            j++;
            k++;
        }
}
void MergeSort(int A[],int l,int r){
    if(l<r){
    //printf("Mergesort called! ");
    int med;
    med=(l+r)/2;
    MergeSort(A,l,med);
    MergeSort(A,med+1,r);
    Merge(A,l,med,r);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    MergeSort(A,0,n-1);
    //printf("Returned\n");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}