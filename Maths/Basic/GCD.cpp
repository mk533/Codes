// GCD of two numbers , Iterative and Recusrion. — O(log(a + b)) = O( log( Max(a,b) ) )
// https://codility.com/media/train/10-Gcd.pdf



#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;

int GCD(int a, int b)
{
    if ( a == 0 )
        return b;
    if ( b == 0 )
        return a;
    
    int temp;
    while ( b%a ) {
        temp = b;
        b = a;
        a = temp % a;
        
    }
    return a;
}

int gcdExtended(int a, int b, int *x, int *y) // gives x and y for  a*x + b*y = GCD(a,b) (Used in RSA algorithm)
 {
 
     if (a == 0)
     {
     *x = 0;
     *y = 1;
     return b;
     }
     
     int x1, y1;
     int gcd = gcdExtended(b%a, a, &x1, &y1);
     
     
     *x = y1 - (b/a) * x1;
     *y = x1;
     
     return gcd;
 }


int  GCD_REC(int a, int b)
{
    if( b == 0)
        return a;
    
    return GCD_REC( b, a % b);
}
int main()
{
    int a;
    int b;
    
    scanf("%d %d",&a,&b);
    printf("%d %d ",a,b);
    
    printf("\nGCD of %d  %d =  %d \n",a,b,GCD(a, b));
    printf("GCD of %d  %d =  %d \n",a,b,GCD_REC(a, b));
    return 0;
}
