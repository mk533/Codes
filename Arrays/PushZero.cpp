
/*Push Zero to end and order of elements should be maintained*/

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
int main()
{
    int n;
    vector<int> A;
    
    printf("Enter n \n");
    scanf("%d",&n);
    
    for (int i = 0;  i < n ; i++) {
        int p;
        scanf("%d",&p);
        A.push_back(p);
    }
    int count = 0;
    for (int i = 0 ; i < n ; i++) {
        if ( A[i] ) {
            A[count++] = A[i];
        }
            
    }
    while ( count < n ) {
        A[count++] = 0;
    }
    Print(A);
    return 0;
}



