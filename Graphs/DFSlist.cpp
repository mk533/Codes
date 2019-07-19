/*DFS of graph (List implementation)*/

#include<cstdio>
#include<cstdlib>
#include<list>
#include<vector>
#include<stack>

using namespace std;

void DFSvisit(vector<list<int> > Adj, vector<int> &visit,int k)
{
    visit[k] = 1;
    printf("%d -->",k);
    list<int> :: iterator it;
    for(it = Adj[k].begin(); it != Adj[k].end(); it++) {
        if(visit[*it] == 0)
            DFSvisit(Adj,visit,*it);
    }
}
void DFS(vector<list<int> > Adj, int k)
{
    int n = Adj.size();
    vector<int>  visit(n,0);
    DFSvisit(Adj,visit,k);
}
int main()
{
    int n;
    int e;
    
    printf("\n enter no of nodes and edges\n");
    scanf("%d%d",&n,&e);
    
    vector<list<int> > Adj(n+1);
    
    for(int i = 0 ; i < e; i++) {
        int v1;
        int v2;
        
        scanf("%d %d",&v1,&v2);
        
        Adj[v1].push_back(v2);
        Adj[v2].push_back(v1);
    }
    list<int> :: iterator it;
    for(int i = 0; i < Adj.size(); i++) {
        printf("%d |",i);
        for(it = Adj[i].begin(); it != Adj[i].end(); it++ ) {
            printf("%d-->",*it);
        }
        printf("\n");
    }
    DFS(Adj,2);
}
