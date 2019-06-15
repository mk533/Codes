
/*
 Euler's Totient of a number is , number which are relative prime to n
 
 Phi(p) = p-1 , p is prime number
 Phi(ab) = Phi(a) * Phi(b)
 Phi(p^k) = p^k – p^ (k-1)
 
 */
#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;

int Phi(int n)
{
    int res = n;
    
    for (int p = 2; p <= sqrt(n) ; p++)
    {
        if( n % p == 0 ) {
            while( n % p == 0 ) {
                n =  n/p;
            }
            res = res - (res / p);
        }
    }
    if(n > 1)
        res = res - (res/n);
    
    return res;
}
int main()
{
    int n;
    
    printf("Enter n\n");
    scanf("%d",&n);
    
    printf("Phi(%d) = %d\n",n,Phi(n));
    return 0;
}
