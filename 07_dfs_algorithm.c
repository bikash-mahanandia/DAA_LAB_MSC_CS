#include<stdio.h>
#define max 5
    int adj[max][max]={{0,1,1,0,0},
                       {1,0,0,1,1},
                       {1,0,0,0,0},
                       {0,1,0,0,0},
                       {0,1,0,0,0}};
        int visit[max]={0};

void dfs(int node){
    printf("%d->",node);
    visit[node]=1;
    for(int i=0; i<max; i++){
        if(adj[node][i]==1 && visit[i]==0){
            dfs(i);
        }
    }
}

int main()
{
    printf("DFS traversal : ");
    dfs(0);
    return 0;
}