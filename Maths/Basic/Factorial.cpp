
// Factorial of a number;


#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;



int  Factorial(int a)
{
    return ( a == 0 || a == 1) ? 1 : a * Factorial(a-1);
}
int main()
{
    int a;
    
    scanf("%d",&a);
    printf("Factorial of %d  is %d \n",a,Factorial(a));
    
    return 0;
}

