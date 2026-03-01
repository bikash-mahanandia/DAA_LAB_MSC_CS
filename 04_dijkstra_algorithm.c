// Program to implemennt dijkstra's algorithm.

#include<stdio.h>
int main(){
    int cost[10][10],dist[10],path[10][10];
    int n,v,p,row,col,min,index=1;
    int i,j;

    printf("Number of nodes: ");
    scanf("%d",&n);

    printf("Cost Matrix (%dx%d):\n", n, n);
    for(i=1; i<=n; i++){
        printf("Row %d: ", i);
        for(j=1; j<=n; j++){
            scanf("%d",&cost[i][j]);
        }
    }

    printf("Destination node: ");
    scanf("%d",&v);

    printf("Number of paths to compare: ");
    scanf("%d",&p);

    printf("Enter paths (row by row):\n");
    for(i=1; i<=p; i++){
        printf("Path %d: ", i);
            for(j=1; j<=n; j++){
                scanf("%d",&path[i][j]);
        }
    }


    for(i=1; i<=p; i++){
        dist[i]=0;
        row=1;
        
    for(j=1; j<n; j++){
        if(row!=v){
            col=path[i][j+1];
            dist[i]=dist[i]+cost[row][col];
        }
        row=col;
    }

    }
min=dist[1];
for(i=1;i<=p;i++){
    if(dist[i]<=min){
        min=dist[i];
        index=i;
    }
}
printf("\nShortest Path Cost : %d", min);
printf("\nOptimal Route : ");
for(i=1; i<=n; i++){
    if(path[index][i]!=0){
        printf("%d->",path[index][i]);
    }
}

return 0;

}