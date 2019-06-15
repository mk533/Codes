
// Nth Fibonacci Number using Matrix - O(log n)
// we move toward bigger numbers in fibonacci series, the consecutive number grows as: F(n) = 1.618*F(n-1) The constant 1.61803 is called Golden ratio.
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

void MatrixMul(int A[2][2], int B[2][2])
{
    int x =  A[0][0] * B[0][0] + A[0][1] * B[1][0];
    int y =  A[0][0] * B[0][1] + A[0][1] * B[1][1];
    int z =  A[1][0] * B[0][0] + A[1][1] * B[1][0];
    int w =  A[1][0] * B[0][1] + A[1][1] * B[1][1];
    
    A[0][0] = x;
    A[0][1] = y;
    A[1][0] = z;
    A[1][1] = w;
    
}
void Pow(int A[2][2],int n)
{
    if(n == 1 || n == 0)
        return ;
    
   int T[2][2]  = { {1,1}, {1,0} };
    
    Pow(A,n/2);
    
    MatrixMul(A,A);
    
    if(n%2)
        MatrixMul(A,T);
    
}
int Fibonacci(int n)
{
    int A[2][2]  = { {1,1}, {1,0} };
    
    if( n == 0)
        return 0;
    Pow(A,n-1);
    for (int i = 0; i < 2; i++ ) {
        for (int j = 0; j < 2; j++ ) {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    return A[0][0];
    
}
int main()
{
    int n,r;
    
    printf("Enter n \n");
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        printf("\n---------\n");
        printf("\n****%",Fibonacci(i));
    }
    printf("\n");
    return 0;
}

