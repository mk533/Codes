
/*Left Rotate Array using Juggling method*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>

using namespace std;

void Print(vector<int> A)
{
    
    for (int i = 0;  i < A.size() ; i++) {
        printf("%d  ", A[i]);
    }
    printf("\n--------------------\n");
    
}


int GCD(int a, int b)
{
    if( b == 0)
        return a;
    
    return GCD(b,a%b);
}

void RotateLeft(vector<int> &A,int d, int n)
{
    if(n == 0 )
        return;
    int gcd = GCD(d,n);
    
    for(int i = 0 ; i < gcd ; i++ ) {
        
        int  j = i;
        int temp = A[i];
        int k;
        while(1) {
            k =  j + d;
            
            if(k >= n)
                k =  k - n;
                
            if(k == i)
                break;
            A[j] = A[k];
            j = j + d;
        }
        A[j] = temp;
    }
}


int main()
{
    int n;
    vector<int> A;
    
    printf("Enter n \n");
    scanf("%d",&n);
    
    for (int i = 0;  i < n ; i++) {
        int k;
        scanf("%d",&k);
        A.push_back(k);
    }
    
    printf("\nSorted Rotated Array :\n");
    
    Print(A);
    
    int d;
    printf("Enter no of left rotations\n");
    scanf("%d",&d);
    RotateLeft(A,d,n);
    
    Print(A);
}


