/*Bit manipulation Operations*/

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>

using namespace std;

int Powerof2(int x)
{
    if( x == 0)
        return 0;
    else
        return (x & x-1);
}

int Count1(int n) {
    
    int count = 0;
    
    while(n)
    {
        n = n & n-1;
        count++;
    }
    return count;
}

void Binary(vector<int> &V,int n)
{
    if(n <= 0)
        return;
    while(n) {
        V.insert(V.begin(),n%2);
        n =  n / 2;
    }
}

void Print(vector<int> V)
{
    for(int i = 0; i < V.size(); i++) {
        printf("%d ",V[i]);
    }
    printf("\n");
}


bool CheckISet(int i, int n)
{
    if(n <= 0)
        return 0;
    else
        return (n &  1 << i);
}

int rightmostUnSet(int n)
{
    if(n == 0)
        return 0;
    if( ( n & n+1) == 0)
        return n;
    else
        return log2(n&-n)+1 ;
}
int main()
{
    int n;
    scanf("%d",&n);
    
    vector<int> V;
    Binary(V,n); // Binary form for positive numbers
    Print(V);
    printf("%d",rightmostUnSet(~n));
   // Powerof2(n) == 0 ? printf("%d is  power of 2",n) : printf("%d is not power of 2",n);
    
   // printf("%d have %d no of 1's\n",n,Count1(n));
 
    /*   int i;
    printf("enter i to be check for set bit or not set\n");
    scanf("%d",&i);
    printf("%d bit in %d is %d ",i,n,CheckISet(i,n)); // checking ith bit in 'n' Set or not Set */
    
    
    
    // x & (-x) : Returns the rightmost 1(set bit) in binary representation of x
    // log2(n&-n)+1 : Returns the rightmost 0(unset bit ) in binary reperesentation of x
    return 0;
}
