
#include<cstdio>
#include<cstdlib>
#include<list>
#include<vector>
#include<queue>

using namespace std;


void BFS(vector<list <int> > Adj, int k)
{
    int n = Adj.size();
    
    vector<int> visited(n,0);
    queue<int> Q;
    list<int> :: iterator  it;
    
    
    Q.push(k);
    visited[k] = 1;
    
    while (!Q.empty()) {
        int node = Q.front();
        printf("%d--> ",node);
        Q.pop();
        for(it = Adj[node].begin() ; it != Adj[node].end() ; it++) {
            if(visited[*it] == 0) {
                Q.push(*it);
                visited[*it] = 1;
            }
        }
        
    }
    printf("\n");
}
int main()
{
    int n;
    int e;
    
    printf("Enter no of Vertices and Edges\n");
    scanf("%d %d",&n,&e);
    
    vector< list<int> > Adj;
    
    Adj.resize(n+1);
    
    printf("Enter Edges\n");
    
    for(int i = 0 ; i < e; i++) {
        int v1;
        int v2;
        scanf("%d%d",&v1,&v2);
        
        Adj[v1].push_back(v2);
        Adj[v2].push_back(v1);
    }
    
    list <int> :: iterator it;
    
    for(int i  = 0 ; i< Adj.size() ; i++) {
        printf("%d |",i);
        for(it = Adj[i].begin() ; it != Adj[i].end() ; it++) {
            printf("%d -->",*it);
        }
        printf("\n");
    }
    printf("BFS : ");
    BFS(Adj,1);
    
}
