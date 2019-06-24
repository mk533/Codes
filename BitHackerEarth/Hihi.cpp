
#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;

int Next ( long long n) {
    
    if ( n == 0)
        return 0;
    if ( (n & n+1) == 0 )
        return n;
    else
        return log2(n & -n) + 1;
}

int main()
{
    int T;
    scanf("%d",&T);
    
    while( T-- ) {
       long long n;
        scanf("%lld",&n);
        long long k = Next(~n);
        long long res = n | (1 << (k-1) );
        printf("%lld\n",res);

    }
    return 0;
}


