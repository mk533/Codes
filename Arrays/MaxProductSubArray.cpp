/*Maximum Product SubArray*/
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>


using namespace std;

void Print(vector<int> A)
{
    
    for (int i = 0;  i < A.size() ; i++) {
        cout<< A[i] <<" ";
    }
    printf("\n--------------------\n");
    
}
int MIN(int a , int b)
{
    return a < b ? a : b;
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
        cin>>p;
        A.push_back(p);
    }
    
    int max_end = 1;
    int min_end = 1;
    int res = 1;
    int temp;
    int flag = 0;
    
    for(int i = 0 ; i <  n; i++) {
        if(A[i] > 0) {
            max_end *= A[i];
            min_end = MIN(1, min_end*A[i]);
            flag = 1;
        }
        else if(A[i] == 0) {
            max_end = 1;
            min_end = 1;
        }
        else {
            temp = max_end;
            max_end = MAX(min_end * A[i],1);
            min_end = temp * A[i];
 
        }
        res = MAX(res,max_end);
    }
    if(flag == 0 && res == 1)
        printf("0\n");
    else
        printf("\n%d\n",res);
    return 0;
    
}




