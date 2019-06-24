#include<cstdio>
#include<cstdlib>
#include<stack>

using namespace std;

int main()
{
    int n;
    stack<int> S;
    
    printf("Enter n\n");
    scanf("%d",&n);
    
    int *A = (int *) malloc(sizeof(int) * n);
    int *st = (int *) malloc(sizeof(int) * n );
    
    for(int i = 0; i < n; i++) {
        scanf("%d",&A[i]);
    }
  
  /*  S.push(0);
    st[0] = 1;
    for (int i = 1; i < n ; i++) {
        
        while(!S.empty() && A[S.top()] <= A[i]) {
            S.pop();
        }
        st[i] = (S.empty()) ? (i + 1) : (i - S.top() );
        S.push(i);
    }
    
     for (int i = 0; i < n ; i++) {
         printf("%d ",st[i]);
     }
   */
    st[0] = 1;
    
    for(int i = 1; i < n; i++) {
        int j = 1;
        while(i - j >= 0 && A[i - j] < A[i] ) {
            j += st[i - j];
        }
        st[i] = j;
        
    }
    for (int i = 0; i < n ; i++) {
        printf("%d ",st[i]);
    }
    
    return 0;
}
