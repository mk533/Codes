
/*Maximum sub array sum in circular array*/
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

int MAX(int a, int b)
{
    return a > b ? a : b;
}
int Kandane(vector<int>  A, int n)
{
    int cur = 0;
    int res = 0;
    
    for(int i = 0 ; i< n ; i++) {
        cur+= A[i];
        if(cur < 0)
        {
            cur = 0;
        }
        res = MAX(res,cur);
    }
    
    return res;
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
    
    int K_sum = Kandane(A,n);
    int total_sum = 0;
    
    for (int i = 0;  i < n ; i++) {
        total_sum += A[i];
        A[i] = -A[i];
    }
    int Non_sum = Kandane(A,n);
    printf("%d",MAX(K_sum,total_sum + Non_sum));
}




