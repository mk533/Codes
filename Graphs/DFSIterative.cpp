/*DFS using Iterative Method*/

#include<cstdio>
#include<cstdlib>
#include<stack>

using namespace std;

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
    printf("-----------\n");

    stack<pair<int,int> > S;
    int visit[n+1];
    
    memset(visit,0,sizeof(visit));
    S.push(make_pair(1,1));
    
    while(!S.empty()) {
        pair<int,int> temp = S.top();
        S.pop();
        
        if(visit[temp.first] == 0)
        {
          printf("%d -->",temp.first);
        }
        
        for(int i = 1; i<= n; i++) {
            if(Adj[temp.second][i] == 1  && visit[temp.second] == 0 ) {
                S.push(make_pair(temp.second,i));
          //      printf("%d, %d\n",temp.second,i);
               
            }
        }
        visit[temp.first] = 1;
    }
    return 0;
}
