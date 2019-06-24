/* Largest power of 2 less than N*/

#include<cstdio>
#include<cstdlib>

using namespace std;

int LargestPower(int n)
{
    n = n | n>>1;
    n = n | n>>2;
    n = n | n>>4;
    n = n | n>>8;
    n = n | n>>16;
    
    return (n+1) >> 1;
}

int main()
{
    int n;
    
    printf("Enter n\n");
    scanf("%d",&n);
    
    printf("Largest power of 2 less than for %d is %d",n,LargestPower(n));
    
    return 0;
}
