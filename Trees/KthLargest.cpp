/* Kth largest element from given array of size n */

#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace std;

int main()
{
    priority_queue <int> Q;
    int n;
    int k;
    
    scanf("%d",&n);
    
    int *a = (int *)malloc(sizeof(int) *n);
    
    for(int i = 0 ; i < n; i++) {
        scanf("%d",&a[i]);
        Q.push(a[i]);
    }
    
    printf("\nEnter k \n");
    scanf("%d",&k);
    k--;
    while(k--)
    {
        Q.pop();
    }
    if(!Q.empty())
        printf("%d",Q.top());
    return 0;
}
