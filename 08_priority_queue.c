#include <stdio.h>
#define MAX 5
struct pq{
    int data;
    int priority;
};
struct pq queue[MAX];
int size = -1;

void enqueue(int value, int priority){
    if (size == MAX - 1){
        printf("Queue is full\n");
        return;
    }

    size++;

    queue[size].data = value;
    queue[size].priority = priority;
}

void display()
{
    if (size == -1){
        printf("Queue is empty\n");
        return;
    }

    struct pq temp[MAX];
    for (int i = 0; i <= size; i++){
        temp[i] = queue[i];
    }
    for (int i = 0; i <= size; i++){
        for (int j = i + 1; j <= size; j++){
            if (temp[i].priority < temp[j].priority){
                struct pq t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }
    printf("\nData   Priority\n");
    for (int i = 0; i <= size; i++)
    {
        printf("%d     %d\n", temp[i].data, temp[i].priority);
    }
}

int main()
{
    int n, value, pr;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &value);

        printf("Enter priority: ");
        scanf("%d", &pr);

        enqueue(value, pr);
    }

    display();

    return 0;
}