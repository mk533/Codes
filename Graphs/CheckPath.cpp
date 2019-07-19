/*check path exists between two cells in matrix or not*/

#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace  std;

int x[] = {0,-1,1,0};
int y[] = {-1,0,0,1};


int BFS(int **A, int **vis,pair<int,int> src,pair<int,int> dest,int n)
{
    queue<pair<int,int> > Q;
    
    Q.push(src);
    pair<int,int> temp;
    vis[src.first][src.second] = 1;
    while(!Q.empty()) {
        temp = Q.front();
        Q.pop();
        
        
        for(int i = 0 ; i < 4; i++) {
            
            if((temp.first+ x[i] >= 0 && temp.first+ x[i] < n &&  temp.second+y[i] >= 0 && temp.second+y[i] < n) && A[temp.first+ x[i]][temp.second+y[i]] == 2) {
             
                return 1;
            }
            if((temp.first+ x[i] >= 0 && temp.first+ x[i] < n &&  temp.second+y[i] >= 0 && temp.second+y[i] < n) && A[temp.first+ x[i]][temp.second+y[i]] == 3 && vis[temp.first+ x[i]][temp.second+y[i]] == 0) {
                
                pair<int,int> temp1;
                vis[temp.first+ x[i]][temp.second+y[i]] = 1;
                temp1.first = temp.first+ x[i];
                temp1.second = temp.second+y[i];
                
                Q.push(temp1);
            }
        }
    }
    return -1;
}
int main()
{
    int n;
    printf("Enter n \n");
    scanf("%d",&n);
    
    pair<int,int> src;
    pair<int,int> dest;
    
    int **A =(int **)malloc(sizeof(int*) * n);
    
    for(int i = 0 ; i < n; i++) {
        A[i] = (int *)malloc(sizeof(int) * n);
    }
    
    for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < n ; j++) {
            scanf("%d",&A[i][j]);
            if(A[i][j] == 1)
                src = make_pair(i,j);
            else if(A[i][j] == 2)
                dest = make_pair(i,j);
        }
    }
    int **vis =(int **)malloc(sizeof(int*) * n);
    
    for(int i = 0 ; i < n; i++) {
        vis[i] = (int *)malloc(sizeof(int) * n);
    }
    
    for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < n ; j++) {
            vis[i][j] = 0;
        }
    }
    if(BFS(A,vis,src,dest,n) == -1)
        printf("NO\n");
    else
        printf("YES\n");
    
    return 0;
}
