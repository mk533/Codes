
//Power function  Pow(a,b) = a^b  => O(log n)
#include<cstdio>
#include<cstdlib>

using namespace std;

int Pow(int a, int b)
{
    if ( b == 0 )
        return 1 ;
    if ( b == 1)
        return a;
    
   int temp = Pow(a, b/2);
    
    if( b%2 == 0)
        return (temp * temp);
    else
        return (temp * temp * a);
}
int main()
{
    int a,b;
    printf("Enter a and b values\n");
    scanf("%d %d",&a,&b);
    printf("Pow(%d,%d) is %d \n",a,b,Pow(a,b));
    return 0;
}


