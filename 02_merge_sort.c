//Program to perform Merge sort.

#include<stdio.h>

void ms(int a[], int lb, int ub);
void mg(int a[], int lb, int mid, int ub);

int main(){
    int a[30], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    
    ms(a, 0, n - 1);

    printf("Sorted array:\n");
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    return 0;
}

void ms(int a[], int lb, int ub){
    int mid;
    if(lb < ub){
        mid = (lb + ub) / 2;
        ms(a, lb, mid);
        ms(a, mid + 1, ub);
        mg(a, lb, mid, ub);
    }
}

void mg(int a[], int lb, int mid, int ub){
    int temp[30];
    int i, j, k;
    i = lb;
    j = mid + 1;
    k = lb;

    while(i <= mid && j <= ub){
        if(a[i] <= a[j]){
            temp[k] = a[i];
            i++;
        } else {
            temp[k] = a[j];
            j++;
        }
        k++;
    }

    if(i > mid){
        while(j <= ub){
            temp[k] = a[j];
            j++;
            k++;
        }
    } else {
        while(i <= mid){
            temp[k] = a[i];
            i++;
            k++;
        }
    }

    for(k = lb; k <= ub; k++){
        a[k] = temp[k];
    }
}

