#include<stdio.h>
#define max 5

int adj[max][max] = {
    {0,1,1,0,0},
    {1,0,0,1,1},
    {1,0,0,0,0},
    {0,1,0,0,0},
    {0,1,0,0,0}
};

int visit[max] = {0};
int queue[max];
int front = -1, rear = -1;

void enqueue(int node){
    if(rear == max-1) return;
    if(front == -1) front = 0;
    queue[++rear] = node;
}

int dequeue(){
    if(front == -1 || front > rear) return -1;
    return queue[front++];
}

void bfs(int start){
    enqueue(start);
    visit[start] = 1;

    while(front <= rear){
        int node = dequeue();
        printf("%d->", node);

        for(int i = 0; i < max; i++){
            if(adj[node][i] == 1 && visit[i] == 0){
                enqueue(i);
                visit[i] = 1;
            }
        }
    }
}

int main(){
    printf("BFS traversal : ");
    bfs(0);
    return 0;
}