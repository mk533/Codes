// Sieve of Eratosthenes  --  O(N log (log N))

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring> // memset is present in this header

using namespace std;


void Sieve_Eratosthenes(int a)
{
    bool A[a+1];
    
    memset(A,true,sizeof(A));
    
    for (int i = 2; i <= sqrt(a) ; i++) {
        
        if( A[i] == true) {
            for( int j = i*i ; j <= a ; j = j + i) {
                A[j]  =  false;
            }
        }
    }
    
    for (int i = 2; i <= a ; i++) {
        if( A[i] == true)
            printf("%d ",i);
    }
    
    printf("\n");
}

int main()
{
    int a;
    
    
    scanf("%d",&a);
    printf("Prime numbers less than %d are\n",a);
    Sieve_Eratosthenes(a);
    return 0;
}



