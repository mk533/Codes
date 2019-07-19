/* Find nth Ugly Number. numbers are numbers whose only prime factors are 2, 3 or 5 */


#include<cstdio>
#include<cstdlib>

using namespace std;

int min(int a, int b)
{
    return a <  b ? a : b;
}
int main()
{
    int n;
    scanf("%d",&n);
    
    int *A = (int *)malloc(sizeof(int) *n);
    
    A[0] = 1;
    
    int i2 = 1;
    int i3 = 1;
    int i5 = 1;
    int next_2 = 2;
    int next_3 = 3;
    int next_5 = 5;
    
   for(int i = 1; i < n; i++) {
      
        A[i] = min(min( next_2,  next_3) , next_5);
        
        if(A[i] ==  next_2) {
            i2++;
            next_2 = A[i2] * 2;
        }
        
        if(A[i] ==  next_3) {
            i3++;
            next_3 = A[i3] * 3;
        }
        
        if(A[i] == next_5) {
            i5++;
            next_5 = A[i5] * 5;
        }
    }
    
    for(int i = 0; i < n; i++) {
        printf("%d ",A[i]);
    }
    return 0;
}
