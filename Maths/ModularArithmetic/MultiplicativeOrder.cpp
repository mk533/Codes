

/* A^k( mod N ) = 1. ( 0 < K < N ) smallest k
 
 */
#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;

int GCD(int a, int b)
{
    if ( a == 0)
        return b;
    
    return GCD(b%a,a);
}
int main()
{
    int a;
    int n;
    int k = 1;
    int temp = 1;
    
    printf("Enter a , n\n");
    scanf("%d %d",&a,&n);
    
    if(GCD(a,n) != 1)
        printf("Multiplicative Order doesnt exists\n");
    
    else
    {
        while( k < n ) {
            
            temp = (temp * a ) % n;
            if(temp == 1)
                break;
            k++;
        }
        printf("Multiplicative Order  is %d\n",k);
    }
    
    return 0;
}
