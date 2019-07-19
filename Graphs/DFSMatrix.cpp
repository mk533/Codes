/*DFS using Adjacency Matrix*/

#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

void DFS(int **Adj, vector<int> &visit,int size, int k)
{
    visit[k] = 1;
    printf("%d -->",k);
    
    for(int i = 1 ; i < size; i++){
        if(Adj[k][i] == 1 && visit[i] == 0) {
            DFS(Adj,visit,size,i);
        }
    }
}


int main()
{
    int n;
    int e;
    
    printf("\nEnter no of Nodes \n");
    scanf("%d",&n);
    
    int **Adj = (int **) malloc(sizeof(int *) * n+1);
    for(int i = 0 ; i < n+1 ; i++) {
        Adj[i] = (int *)malloc(sizeof(int ) * n+1);
    }
    
    for(int i = 1 ; i < n+1 ; i++ ) {
            for(int j = 1 ; j < n+1 ; j++ ) {
                scanf("%d",&Adj[i][j]);
            }
    }
    printf("-----------\n");
    for(int i = 1 ; i < n+1 ; i++ ) {
        for(int j = 1 ; j < n+1 ; j++ ) {
            printf("%d ",Adj[i][j]);
        }
        printf("\n");
    }
    vector<int> visit(n+1,0);
    printf("-----------\nDFS:");
    DFS(Adj,visit,n+1,5);
    return 0;
}
