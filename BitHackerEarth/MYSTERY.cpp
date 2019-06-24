
#include<cstdio>
#include<cstdlib>

using namespace std;

unsigned long long Count1(unsigned long long n) {
    
    int count = 0;
    
    while(n) {
        n = n & n-1;
        count++;
    }
    return count;
}

int main()
{
    unsigned long long n;
    
    while( scanf("%llu",&n) == 1) {
        printf("%llu\n",Count1(n));
    }
    return 0;
}

