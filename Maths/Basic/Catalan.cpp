
// nth catalan nnumber => ( 2n C n ) /  n+1
// NcR used here is O(1) space,
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int Min(int a,int b)
{
    return a < b ? a : b ;
}
unsigned long long int NcR(int n,int r)
{
    if ( r > n -r )
        r = n - r;
    unsigned long long val = 1;
    for (int i = 0; i < r; i++ ) {
        
        val  = val * (n - i);
        val  = val / (i +1 );
    }
    return val;
}

unsigned long long Catalan(int n)
{
    unsigned long long res = NcR(2*n,n);
    return  res/(n+1) ;
}

int main()
{
    int n,r;
    
    printf("Enter n \n");
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        printf("%llu  ",Catalan(i));
    }
    
    return 0;
}
