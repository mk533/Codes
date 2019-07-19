
/*find the position of 0 to be replaced with 1 to get longest continuous sequence of 1s*/
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>

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
    Print(A);
    
    int before_zero = 0 ;
    int after_zero = 0;
    int count = 0;
    int flag = 1;
    int max;
    for(int i = 0 ; i < n ; i++) {
        
        if(A[i] == 1)
            count++;
        if(A[i] == 0 && flag) {
            flag = 0;
            count++;
        }
            
    }
}








