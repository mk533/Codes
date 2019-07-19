
/*Segregrate Even and Odd Numbers in array*/
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
    int j = 0;
    for(int i = 0 ; i < n;i++) {
        
        if(A[i]%2 == 0) {
            A[i] ^= A[j];
            A[j] ^= A[i];
            A[i] ^= A[j];
            
            j++;
        }
    }
    Print(A);
    return 0;
}




