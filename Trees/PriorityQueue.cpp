/*Priority Queue using STL*/

#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace std;

void PrintQ(priority_queue <int> Q)
{
    while( !Q.empty()) {
        printf("%d ",Q.top());
        Q.pop();
    }
    printf("\n----------------\n");
}
int main()
{
    int n;
    priority_queue<int > Q; // priority_queue<int ,vector<int>, greater<int> > Q; min heap
    
    scanf("%d",&n);
    
    while(n--)
    {
        int i;
        scanf("%d",&i);
        Q.push(i);
        PrintQ(Q);
    }
}
