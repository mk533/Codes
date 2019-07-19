
/*BFS  using Adjacency Matrix*/

#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>

using namespace std;


void BFS(int **Adj , int k, int n)
{
    queue<int> Q;
    vector<int> visited(n,0);
    
    Q.push(k);
    visited[k] = 1;
    
    while(!Q.empty()) {
        int temp = Q.front();
        printf("%d -->",temp);
        Q.pop();
        for(int i = 1 ; i < n ; i++) {
            if(visited[i] == 0 && Adj[temp][i] == 1) {
                Q.push(i);
                visited[i] = 1;
            }
        }
    }
    
}
int main()
{
    int n;
    int e;
    
    printf("Enter no of Nodes and no of Edges \n");
    scanf("%d",&n);
    scanf("%d",&e);
    
    int **Adj = (int **) malloc(sizeof(int *) * n+1);
    for(int i = 0 ; i < n+1 ; i++) {
        Adj[i] = (int *)malloc(sizeof(int ) * n+1);
    }
    
    for(int i = 1 ; i < n+1 ; i++) {
        for(int j = 1; j < n+1; j++) {
            Adj[i][j] = 0;
        }
        
    }
    printf("Enter Edges\n");
    for(int i = 0 ;i < e ; i++) {
        int v1;
        int v2;
        
        scanf("%d %d",&v1,&v2);
        Adj[v1][v2] = 1;
        Adj[v2][v1] = 1;
    }
    
    printf("--------------\n");
    for(int i = 1 ; i < n+1 ; i++) {
        for(int j = 1; j < n+1; j++) {
            printf("%d ",Adj[i][j]);
        }
        printf("\n");
    }
    printf("--------------\n");
    
    BFS(Adj,1,n+1);
}/*
  
  
  1 2
  1 3
  2 4
  2 5
  3 5
  4 5
  4 6
  5 6
  */
