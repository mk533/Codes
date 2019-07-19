/*Print Element that occured only once*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>

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
    
    map<int, int> M;
    

    for(int i = 0 ; i < n; i++) {
        M[A[i]]++;
    }
    
    for(auto i = M.begin(); i != M.end(); i++) {
        printf("%d -->%d\n",i -> first,i -> second);
    }
    printf("\n--------------\n");
    for(int i = 0 ; i < n; i++) {
        if( M[A[i]] == 1) {
            printf("%d ",A[i]);
        }
    }
    printf("\n");
    return 0;
}


