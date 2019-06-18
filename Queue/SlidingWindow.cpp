
#include<cstdio>
#include<cstdlib>
#include<deque>

using namespace std;

void SlidingWindow(int *a, int n, int k)
{
    deque <int> Q;
    int i;
    
    for ( i = 0; i < k; i++) {
        
        while( !(Q.empty()) && a[i] >= a[Q.back()])
        {
            Q.pop_back();
        }
        Q.push_back(i);
    }
    
    for(; i < n; i++) {
        printf("%d ",a[Q.front()]);
        
        if(!(Q.empty()) &&  Q.front() <= i - k) {
            Q.pop_front();
        }
        while( !(Q.empty()) && a[i] >= a[Q.back()])
        {
            Q.pop_back();
        }
        Q.push_back(i);
    }
    
    printf("%d ",a[Q.front()]);
}
int main()
{
    int n;
    int k;
    
    printf("Enter the size of array\n");
    scanf("%d",&n);
    
    int *a = (int *)malloc(sizeof(int) * n );
    
    for(int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    
    printf("Enter Window size\n");
    scanf("%d",&k);
    
    SlidingWindow(a,n,k);
    
    return 0;
}
