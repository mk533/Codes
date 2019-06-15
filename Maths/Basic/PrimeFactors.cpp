// Prime Factors of a number  -->  O ( sqrt(n))

#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;


void Prime_Factors(int a)
{
    while ( a % 2 == 0) {
        printf("2\n"); // Prints 2
        a = a / 2;
    }
    
    for (int i = 3; i <= sqrt(a) ; i = i+2 ) {
        
            while( a % i == 0) {
                printf("%d\n",i); // Prints all other prime numbers less than sqrt
                a = a / i;
        }
    }
    if ( a > 2)
        printf("%d\n",a); // if after factorising a > 2 means its prime number , so printing a ; ex:- 111, sqrt(111) ~ 11, here a = 37
}
int main()
{
    int a;
    
    
    scanf("%d",&a);
    printf("Prime Factors of a %d are\n",a);
    Prime_Factors(a);
    return 0;
}


