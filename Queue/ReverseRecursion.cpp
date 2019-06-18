
/*
 Reverse Queue Contents using Recursion
 */

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
void Reverse(queue<int> &q) // &q is passed
{
   // printf("here\n");
    if( q.empty() )
        return;
    
    int data = q.front();
    q.pop();
    Reverse(q);
    q.push(data);
}


int main()
{
    queue <int> Q;
    int n;
    
    printf("Enter the no of Elements inserted into Queue\n");
    scanf("%d",&n);
    
    for (int i = 0 ; i < n ;i++) {
        int k;
        scanf("%d",&k);
        Q.push(k);
    }
    
    
    Print_Queue(Q);
    Reverse(Q);
    printf("---------------------\n");
    Print_Queue(Q);
    
    return 0;
}

