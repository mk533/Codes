/*Search Element Sorted Rotated Array*/

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

int FindPivot(vector<int> A,int low,int high)
{
    if ( low > high)
        return -1;
    if ( low == high)
        return low;
    
    int mid  = low + (high - low) / 2;
    
    if( mid > low  && A[mid] < A[mid -1])
        return (mid - 1);
    
    if( mid < high  && A[mid] > A[mid +1])
        return mid;
    
    if(A[low] < A[mid])
        return FindPivot(A,mid+1,high);
    else
        return FindPivot(A,low,mid-1);
}

void BinarySearch(vector<int> A,int low, int high,int ele)
{
    int l = low;
    int h = high;
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
    
    printf("\nSorted Rotated Array :\n");
    
    Print(A);
    
    int pivot = FindPivot(A,0,n - 1);
    printf("pivot element is at %d \n",pivot);
    
    int ele;
    printf("Enter the element to be searched \n");
    
    scanf("%d",&ele);
    
    if(pivot != -1) {
        if( A[pivot] == ele) {
            printf("Element found at %d\n",pivot);
        }
       else if(A[0] > ele)
            BinarySearch(A,pivot+1,n-1,ele);
        else
            BinarySearch(A,0,pivot-1,ele);
    }
    else
        BinarySearch(A,0,n-1,ele);
    return 0;
}


