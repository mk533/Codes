
/* a x ≡ 1 (mod m) => x exists only when gcd(a,m) =1

 a*x + b*y = gcd(a, b)  // Extended Euclidean
 
 a*x + m*y = 1

 a*x + m*y ≡ 1 (mod m)
 
 a*x  ≡ 1 (mod m)
 
 we can get x value from Extended Euclidean
 
 a*x + b*y = gcd(a, b)
 
 x = y1 - b/a * x1
 y = x1
 
 
 */
#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;

int ExtEuc(int a, int m,int *x, int *y)
{
    if ( a == 0)
    {
        *x = 0;
        *y = 1;
        return m;
    }
    
    int x1;
    int y1 ;
    int gcd = ExtEuc(m%a,a,&x1,&y1);
    
    *x = y1 - ( m / a) * x1;
    *y = x1;
    
    return gcd;
}

int main()
{
    int a;
    int m;
    
    int x;
    int y;
    printf("Enter a , m\n");
    scanf("%d %d",&a,&m);
    
    int gcd;
    gcd = ExtEuc(a,m,&x,&y);
    
    printf("gcd is %d\n",gcd);
    
    if ( gcd != 1 )
        printf("\nMultiplicative Inverse doesnt exists\n");
    else
        x = ( x%m + m ) % m; // to handle negative number cases
    printf("Modular Multiplicative Inverse is  %d",x);
    
    return 0;
}
