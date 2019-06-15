

/*
 Given three numbers x, y and p, compute (x^y) % p
 
 if b is even:
 (a ^ b) % c = ((a ^ b/2) * (a ^ b/2))%c
 
 if b is odd:
 (a ^ b) % c = (a * (a ^( b-1))%c
 
 
 O(Log y)
 */
#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;

int ModExp(int x, int y, int p)
{
    if( y == 0 )
        return 1;
    
    if( y == 1)
        return x;
    
    
    long  temp ;
    
    if ( y%2 == 0 )
    {
        temp = ModExp(x,y/2,p);
        temp = ( temp * temp ) % p;
    }
    
    else
    {
        temp = x % p;
        temp = ( temp * ModExp(x,y-1,p) % p ) % p;
    }
    return (temp + p ) % p; // to handle negative numbers
}
int main()
{
    int x;
    int y;
    int p;
    
    printf("Enter x , y and p\n");
    scanf("%d %d %d",&x,&y,&p);
    
    printf("(%d ^ %d ) %% %d = %d \n",x,y,p,ModExp(x,y,p));
    return 0;
}
