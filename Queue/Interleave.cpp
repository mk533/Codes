/*
 Interleave the first half elements of the queue with second half
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

void Print_Stack(stack<int> s)
{
    while(!s.empty()) {
        printf("%d ",s.top());
        s.pop();
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
    
    int size = Q.size();
    int mid = size / 2;
    int temp;
    
    while( mid-- )
    {
        S.push(Q.front());
        Q.pop();
    }
    
    
  //  Print_Queue(Q);
   // Print_Stack(S);
    
   // printf("\n---------------------\n");
    
    while( !S.empty() )
    {
        Q.push(S.top());
        S.pop();
    }
    
   // Print_Queue(Q);
  //  Print_Stack(S);
    
   // printf("\n---------------------\n");
    
    
    mid = size / 2;
    
    while( mid-- ) {
        temp = Q.front();
        Q.pop();
        Q.push(temp);
    }
    
  //  Print_Queue(Q);
  //  Print_Stack(S);
    
   // printf("\n---------------------\n");
    
    mid = size / 2;
    while( mid-- )
    {
        S.push(Q.front());
        Q.pop();
    }
    
  //  Print_Queue(Q);
    //Print_Stack(S);
    
//    printf("\n---------------------\n");
    
    mid = size / 2;
    
    while( mid-- )
    {
        Q.push( S.top() );
        S.pop();
        temp = Q.front();
        Q.pop();
        Q.push(temp);
    }
    
    Print_Queue(Q);
   // Print_Stack(S);
    
  //  printf("\n---------------------\n");
    return 0;
}

