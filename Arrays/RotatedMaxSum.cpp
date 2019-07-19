
/*Maximum possbile of summation of i*arr[i]*/

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


int Max(int a, int b)
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
        int k;
        scanf("%d",&k);
        A.push_back(k);
    }
    
    Print(A);
    int sum = 0;
    int cur = 0;
    
    for(int i = 0 ; i < n; i++) {
        sum += A[i];
        cur += (i*A[i]);
    }
    int max = cur;
    for(int i = 1; i < n; i++) {
      cur += ( (sum - n*A[n-i]));
      max = Max(max,cur);
    }
    printf("%d \n",max);
}



