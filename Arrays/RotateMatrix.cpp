/*Rotate Matrix Clockwise*/

#include<cstdio>
#include<cstdlib>

using namespace std;


void Print(int **a, int n, int m)
{
    for(int i = 0; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n----------\n");
}

void Rotate(int **A, int n, int m)
{
   
    int right = 0;
    int down = 0;
    int cur,prev;
   
    while ( down < n && right < m) {
        
        if( down+1 == n || right+1 == m)
            break;
        
        prev = A[down+1][right];
        
        for(int i = right; i < m ; i++) {
            cur = A[down][i];
            A[down][i] = prev;
            prev = cur;
        }
        down++;
        
        for(int i = down; i < n; i++) {
            cur = A[i][m-1];
            A[i][m-1] = prev;
            prev = cur;
        }
        m--;
        if(down < n) {
            for(int i = m-1 ; i >= right ;i--) {
                
                cur = A[n-1][i];
                A[n-1][i] = prev;
                prev = cur;
            }
        }
        n--;
        
        if(right < m) {
            for(int i = n-1;i >= down ;i--) {
                
                cur = A[i][right];
                A[i][right] = prev;
                prev = cur;
            }
        }
        right++;
    }
 
    
}
int main()
{
    int n,m;
    printf("Enter no of rowse and columns \n");
    scanf("%d%d",&n,&m);
    
    int **A = (int **) malloc(sizeof(int*) * n);
    
    for(int i = 0; i < n ; i++) {
        A[i] = (int *) malloc(sizeof(int) * m);
    }
    
    for(int i = 0; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            scanf("%d",&A[i][j]);
        }
    }
    
    Print(A,n,m);
    Rotate(A,n,m);
    Print(A,n,m);
}
