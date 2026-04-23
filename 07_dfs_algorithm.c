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

void bfs(int node){
    int front = 0, rear = 0;

    printf("%d->", node);
    visit[node] = 1;
    queue[rear] = node;

    while(front <= rear){
        node = queue[front++];

        for(int i = 0; i < max; i++){
            if(adj[node][i] == 1 && visit[i] == 0){
                printf("%d->", i);
                visit[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main(){
    printf("BFS traversal : ");
    bfs(0);
    return 0;
}