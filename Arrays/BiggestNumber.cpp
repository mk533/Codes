/*Arrange given numbers to form the biggest number*/
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>


using namespace std;

void Print(vector<string> A)
{
    
    for (int i = 0;  i < A.size() ; i++) {
        cout<< A[i] <<" ";
    }
    printf("\n--------------------\n");
    
}
bool comp(string A,string B)
{
    string AB = A.append(B);
    string BA = B.append(A);
    
    return AB > BA ? true : false;
}
int main()
{
    int n;
    vector<string> A;
    
    printf("Enter n \n");
    scanf("%d",&n);
    
    for (int i = 0;  i < n ; i++) {
        string p;
        cin>>p;
        A.push_back(p);
    }

    
    Print(A);
    
    sort(A.begin(),A.end(),comp);
    Print(A);

    return 0;
}




