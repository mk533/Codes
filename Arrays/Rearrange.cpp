/*Rearrange an array such that arr[i] = i*/
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
    int temp1;
    int temp2;
    for (int i = 0 ; i < n ;) {
       
        if(A[i] >= 0 && A[i] != i) {
            temp1 = A[i];
            temp2 = A[temp1];
            A[i] = temp2;
            A[temp1] = temp1;
        }
        else
            i++;
    }
    
    Print(A);
    return 0;
}



