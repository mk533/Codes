

/*Subsequence of length 3  in increasing order*/
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
    
    vector<int> left(n);
    vector<int> right(n);
    
    int min = 0;
    left[0] = -1;
    for(int i = 1 ; i < n ;i++) {
        if(A[i] <= A[min]) {
            min = i;
            left[i] = -1;
        }
        else
            left[i] = min;
    }
    Print(left);
    int max = n - 1;
    right[n-1] = -1;
    for(int i = n - 2; i >= 0; i--) {
        if(A[i] >= A[max]) {
            max = i;
            right[i] = -1;
        }
        else
            right[i] = max;
    }
    Print(right);
    
    for(int i = 0 ; i < n ; i++) {
        if(left[i] != -1 && right[i]!= -1 ) {
            printf("%d %d %d \n",A[left[i]],A[i],A[right[i]]);
        }
    }
}




