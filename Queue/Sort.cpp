/*
Sort Contents of Queue without extra space
 */

#include<cstdio>
#include<cstdlib>
#include<queue>
#include<climits>

using namespace std;

void Print_Queue(queue<int> q)
{
    while(!q.empty()) {
        printf("%d ",q.front());
        q.pop();
    }
    printf("\n");
}
int getMin(queue<int> &q, int n)
{
    int size = q.size();
    int min = INT_MAX;
    int min_index = -1;
    int temp;
    
    for (int i = 0; i < size; i++ )
    {
        temp = q.front();
        q.pop();
        if ( min >= temp && i <= n ) {
            min = temp;
            min_index = i;
        }
        q.push(temp);
    }
   // printf("-------%d \n",min_index);
    return min_index;
}
void Moveback(queue<int> &q ,int min_index) {
    int size = q.size();
    int temp;
    int val;
    for (int i = 0; i < size; i++ )
    {
        int curr = q.front();
        q.pop();
        if (i != min_index)
            q.push(curr);
        else
            val = curr;
    }
    q.push(val);
}

void Sort(queue<int> &q)
{
    int size = q.size();
    while(size--) {
        int min_index = getMin(q,size);
        Moveback(q,min_index);
    }
    
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
    Sort(Q);
    printf("---------------------\n");
    Print_Queue(Q);
    
    return 0;
}

