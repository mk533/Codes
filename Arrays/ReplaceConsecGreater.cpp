/* Replace two consecutive equal values with one greater */
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>

using namespace std;

void Print(vector<int> A)
{
    
    for (int i = 0;  i < A.size() ; i++) {
        printf("%d ",A[i]);
    }
    printf("\n--------------------\n");
    
}

int MAX(int a, int b)
{
    return a > b ? a : b;
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
    Print(A);
    int pos = 0;
    for(int i = 0 ; i  < n; i++) {
        A[pos++] = A[i];
        while (pos > 1 && A[pos - 2 ] == A[pos -1]) {
            pos--;
            A[pos-1]++;
        }
            
    }
    for(int i = 0 ; i< pos; i++) {
        printf("%d ",A[i]);
    }
}








