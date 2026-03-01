//Program to perform Heap sort.

#include<stdio.h>
void max_heapify(int a[],int,int);
void build_max_heap(int a[],int);
void heap_sort(int a[],int);

int main(){
    int n,i,hs;
    int a[50];

    printf("Enter the number of Elements : ");
    scanf("%d",&n);

    printf("Enter the Array : ");
    for(i=0; i<n; i++){
        scanf("%d",&a[i]);
    }

    hs=n-1;
    heap_sort(a,hs);

    for(i=0; i<n; i++){
        printf("%d ",a[i]);
    }

    return 0;
}

void max_heapify(int a[],int i,int hs){
    int temp,largest,left,right;
    
    left = 2*i;         
    right = 2*i+1;
    
    if(left<=hs && a[left]>a[i]){
        largest = left;
    }else{
        largest = i;
    }

    if(right<=hs && a[right]>a[largest]){
        largest=right;
    }
    
    if(largest!=i){
            temp=a[i];
            a[i]=a[largest];
            a[largest]=temp;
            max_heapify(a,largest,hs);
        }
    }

void heap_sort(int a[],int hs){
    int i,temp; 
    build_max_heap(a,hs);
   
    for(i=hs; i>=0; i--){ 
        temp=a[i];
        a[i]=a[0];   
        a[0]=temp;
        hs--; 
        max_heapify(a,0,hs);
    } 
}

void build_max_heap(int a[],int hs){
    int i;
    for(i=hs/2; i>=0; i--){       
        max_heapify(a,i,hs);
    }
    
}