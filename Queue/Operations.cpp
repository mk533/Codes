/*Basic Queue Operations */

#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace std;

int main()
{
    queue <int>  Q;
    
    int n;
    
    printf("Enter the no of elements to be inserted into queue\n");
    scanf("%d",&n);
    
    for (int i = 0 ; i < n ;i++) {
        int k;
        scanf("%d",&k);
        Q.push(k); // Enqueueing elements into front of Queue
    }
    
    printf("size of queue %lu \n",Q.size());
    
    while(!Q.empty()) {           // returns True if Queue
        printf("%d ",Q.front()); // printing front element
        Q.pop();                 // Dequeue elements from front
    }
    printf("\n");
    return 0;
}
