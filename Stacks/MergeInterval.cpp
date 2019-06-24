/*Merge Overlapping Intervals without using stack*/
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<algorithm>

using namespace std;

struct Interval
{
    int s;
    int e;
};
bool compare(Interval I1, Interval I2)
{
    return I1.s < I2.s;
}
int main()
{
    int n;
    
    printf("Enter no of Intervals \n");
    scanf("%d",&n);
    
    struct Interval *A = (struct Interval *) malloc(sizeof(struct Interval) *n);
    
    for (int i = 0; i < n; i++) {
        int start;
        int end;
        
        scanf("%d %d",&start,&end);
        A[i].s = start;
        A[i].e = end;
    }
    
    sort(A,A+n,compare);
    
    printf("-----------------\n");
    
    for (int k = 0; k < n; k++) {
        
        printf("%d %d\n",A[k].s,A[k].e);
    }
    
    printf("-----------------\n");
    
    int j = 0; ;
    
    for ( int i = 0 ; i < n ; i++) {
        
        if ( j != 0 && A[j-1].e >= A[i].s ) {
            A[j-1].e = max(A[j-1].e,A[i].e);
        }
        else
        {
            A[j++] = A[i];
        }
        
    }
    for (int k = 0; k <j; k++) {
        
        printf("%d %d\n",A[k].s,A[k].e);
    }
    return 0;
}
