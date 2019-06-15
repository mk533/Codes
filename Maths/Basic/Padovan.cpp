// P(n) = P(n-2) + P(n-3)
//P(0) = P(1) = P(2) = 1

//https://en.wikipedia.org/wiki/Padovan_sequence

#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    int n;
    
    printf("Enter n\n");
    scanf("%d",&n);
    
    int P0 = 1;
    int P1 = 1;
    int P2 = 1;
    int temp;
    
    n = n - 3;
    printf("%d %d %d ",P0,P1,P2);
    
    while(n > 0)
    {
        printf("%d ",P0 + P1);
        
        temp = P2;
        P2 = P0 + P1;
        P0 = P1;
        P1 = temp;
        
        n--;
    }
}
