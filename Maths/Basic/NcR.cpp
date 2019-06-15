// O(n*k) time
// O(n*k) space complexity  -> reduced to O(n) space;
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int Min(int a,int b)
{
    return a < b ? a : b ;
}

/*
unsigned long long NcR(int n, int r)
{
    if ( r == 0 || r == n)
        return 1;
    return NcR(n-1, r-1) + NcR(n-1, r);
}
*/
/*
unsigned long long NcR(int n, int r)
{
    int **A = (int **)malloc(sizeof(int *) *(n+1) );
    
    for (int i = 0 ; i < n+1; i++) {
        
        A[i] = (int *) malloc(sizeof(int) * (r+1));
    }
    
    
    for (int i = 0 ; i < n+1 ; i++) {
        
        for (int j = 0; j <= Min(i,r); j++) {
          
            if (j == 0 || j == i)
                A[i][j] = 1;
            else
                A[i][j] = A[i-1][j-1] + A[i-1][j];
        }
    }
    return A[n][r];
 
}
 */
unsigned long long NcR(int n, int r)
{
    int *A = (int *) malloc(sizeof(int) * (n+1));
    
    A[0] = 1;
    
    for (int i = 0; i< n+1 ; i++) {
        
        for ( int j = Min(i,r); j >0; j--) {
            
            A[j] = A[j] + A[j-1]; // why to come from back?  if you access from front, while upadation previous values can't be used as there are updated.
            printf("%d ",A[j]);
        }
        printf("\n------------------\n");
    }
    return A[r];
}

int main()
{
    int n,r;
    
    printf("Enter n and r values\n");
    scanf("%d %d",&n,&r);
    
    printf("%dc%d = %llu", n, r, NcR(n,r) );
    return 0;
}
