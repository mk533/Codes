/*Reverse contents of Queue*/

#include<cstdio>
#include<cstdlib>
#include<queue>
#include<stack>

using namespace std;

void Print_Queue(queue<int> q)
{
    while(!q.empty()) {
        printf("%d ",q.front());
        q.pop();
    }
    printf("\n");
}
int main()
{
    queue <int> Q;
    stack <int> S;
    int n;
    
    printf("Enter the no of Elements inserted into Queue\n");
    scanf("%d",&n);
    
    for (int i = 0 ; i < n ;i++) {
        int k;
        scanf("%d",&k);
        Q.push(k);
    }
    
    while ( !Q.empty() ) {
        S.push( Q.front() );
        Q.pop();
    }
    
    while(!S.empty())
    {
        Q.push( S.top() );
        S.pop();
    }
    
    Print_Queue(Q);
    
    return 0;
}
