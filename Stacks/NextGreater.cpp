/*Next Greatest Element*/

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
    
    int *a  = (int *) malloc(sizeof(int) * n);
    
    for (int  i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    
    
    for (int i = n - 1; i >=0 ; i--)
    {
        if( S.empty() ) {
           // printf("-1 ");
            S.push(a[i]);
            a[i] = -1;
        }
        else {
            
      
            while (!S.empty() && S.top() < a[i] ) {
                S.pop();
            }
            if( S.empty() ) {
              //  printf("-1 ");
                S.push(a[i]);
                a[i] = -1;
            }
            else
            {
                int temp = S.top();
                S.push(a[i]);
                a[i] = temp;
            }
        }
    }
    
    for (int i = 0 ;i < n; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
