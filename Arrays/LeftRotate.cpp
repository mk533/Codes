/*Printing Left Rotated Array*/

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
        int k;
        scanf("%d",&k);
        A.push_back(k);
    }
    
    printf("Enter no of times array to be rotated\n");
    int p;
    scanf("%d",&p);
    
    p =  p % n;
    
    for(int i = 0; i < n; i++) {
        printf("%d ",A[(p+i)%n]);
    }
    printf("\n");
}

