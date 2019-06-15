// LCM of two numbers

// a x b = LCM(a, b) * GCD (a, b)
#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;



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
    
    int g = GCD_REC(a,b);
    printf("LCM of %d %d is %d \n", a, b, (a *b) / g);
    return 0;
}

