#include<cstdio>
#include<cstdlib>
#include<climits>

using namespace std;

int main()
{
    int T;
    
    scanf("%d",&T);
    
    while ( T-- ) {
        
        int n;
        int max = INT_MIN;
        
        scanf("%d",&n);
        
        int *A = (int *) malloc (sizeof(int) *n);
        
        for(int i = 0 ; i < n ; i++) {
            scanf("%d",&A[i]);
        }
        
        int res ;
        int max_index ;
        
        for(int i = 0 ; i < 32 ; i++) {
            
            res = 0;
            
            for(int j = 0 ; j < n ; j++) {
                
                if( A[j] & (1 << i) ) {
                    res++;
                }
            }
            if(res > max ) {
                
                max = res;
                max_index = i;
                
                //printf("%d-->%d \n",max_index,max);
            }
        }
        printf("%d\n", max_index );
    }
    return 0;
}
