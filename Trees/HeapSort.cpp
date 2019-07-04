/*Heap Sort*/

#include<cstdio>
#include<cstdlib>

using namespace std;


void Heapify(int *A, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int parent = i;
    
    if( left < n && A[left] > A[parent] ) {
        
        A[left] ^= A[parent];
        A[parent] ^= A[left];
        A[left] ^= A[parent];
    }
    if( right < n && A[right] > A[parent] ) {
        
        A[right] ^= A[parent];
        A[parent] ^= A[right];
        A[right] ^= A[parent];
    }
}
void Print(int *a, int n)
{
    for(int i = 0; i < n; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void HeapSort(int *a, int n)
{
    int size = n;
    int low = 0;
    while(size > 1) {
        
        for(int i = size / 2  - 1; i >= 0; i--) {
            Heapify(a,size,i);
        }
        size--;
     //   Print(a,n);
       // printf("#################\n");
        a[low] ^= a[size];
        a[size] ^= a[low];
        a[low] ^= a[size];
        Print(a,n);
        printf("---------------\n");
        
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    
    int *a = (int *)malloc(sizeof(int) *n);
    
    for(int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    printf("---------------\n");
    HeapSort(a,n);
    Print(a,n);
    printf("\n");
    
}
