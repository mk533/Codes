
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    
    while( T-- ) {
        
        int n;
        int count  = 0;
        
        scanf("%d",&n);
        
        for(int i = 1 ; i <= n; i++) {
            for(int j = i+1 ; j <= n ; j++ ) {
                if( (i ^ j) <= n) {
                    count++;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
