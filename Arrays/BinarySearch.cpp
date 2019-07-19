/*Iterative Binary Search*/

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
    
   // Print(A);
    sort(A.begin(),A.end());
    Print(A);
    
    int ele;
    
    printf("Enter the element to be searched \n");
    
    scanf("%d",&ele);
    
    int l = 0;
    int h = n - 1;
    int mid ;
    int flag = 1;
    while (l <= h) {
        
        mid = (l + h) / 2;
        
        if (A[mid] == ele) {
            flag = 0 ;
            break;
        }
        
        else if (A[mid] < ele) {
            l = mid + 1;
        }
        
        else {
            h = mid - 1;
        }
    }
    
    if(!flag)
        printf("Element found at %d\n",mid);
    else
        printf("Element not found\n");
    return 0;
}
