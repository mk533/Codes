/*Sorting contents of Stack*/

#include<cstdio>
#include<cstdlib>
#include<stack>

using namespace std;

int main()
{
    int n;
    stack <int> S;
    
    printf("Enter the no of elements in Stack\n");
    scanf("%d",&n);
    
    for ( int i = 0 ; i < n; i++) {
        int k;
        scanf("%d",&k);
        S.push(k);
    }
    stack <int> T;
    
    while( !S.empty() ) {
        
        int temp = S.top();
        S.pop();
        
        while( !T.empty() && T.top() > temp)
        {
            int temp2 = T.top();
            T.pop();
            S.push(temp2);
        }
        T.push(temp);
    }
    
    while( !T.empty() ) {
        printf("%d ",T.top());
        T.pop();
    }
    return 0;
}

