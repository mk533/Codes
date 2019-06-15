// Segemented Sieve of Eratosthenes  --
//time complexity by Segmented Sieve is same as Simple Sieve. It has advantages for large ‘n’ as it has better locality of reference and requires O (sqrt(n)) space.


#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring> // memset is present in this header
#include<vector>
using namespace std;


void Sieve_Eratosthenes(int a,vector<int> &arr)
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
        {
            arr.push_back(i);
     //       printf("%d ",i);
        }
    }
    printf("\n");
}

void Segmented_Sieve(int a)
{
    int limit = floor( sqrt(a) ) + 1;
    vector<int> arr;
    
    Sieve_Eratosthenes(limit,arr);
    
    int l = limit;
    int h = 2 * limit;
    
    while( l < a ) {
        if(h >= a)
                h = a;
        
        bool M[limit+1];
        memset(M, true, sizeof(M));
        
        for (int i = 0 ; i < arr.size(); i++ ) {
            
            int low = floor(l/arr[i]) * arr[i];
            
            if (low < l)
                low += arr[i];
            
            for (int j = low; j < h; j += arr[i])
            {
                M[j-l] = false;
            }
        }
        for (int i = l; i < h; i++) {
            
            if (M[i - l] == true)
                printf("%d ",i);
        }
        l = l + limit;
        h = h + limit;
    }
}
int main()
{
    int a;
    
    
    scanf("%d",&a);
    printf("Prime numbers less than %d are\n",a);
    Segmented_Sieve(a);
    return 0;
}




