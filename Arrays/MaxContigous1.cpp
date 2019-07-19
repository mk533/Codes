
/*Maximum Contiguous 1 after k rotations*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<set>

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
    
    int k;
    int j;
    int first;
    int second;
    printf("\nEnter no of rotations allowed\n");
    scanf("%d",&k);
    
    multiset < int, greater<int> > m;
    int count = 0;
    for(int i = 0 ; i < n; i++) {
        if(A[i] == 1) {
            count = 0;
             j = i;
            while(A[j] == 1 && j < n) {
                count++;
                j++;
            }
            i =  j - 1;
            m.insert(count);
        }
        
        
    }
    
    multiset <int , greater<int> >:: iterator it;
   
   /* for( it = m.begin(); it!= m.end(); it++){
        printf("%d ",*it);
    }
    */
    while( k > 0 && m.size() > 1) {
        first = *(m.begin());
        m.erase(*(m.begin()));
        second = *(m.begin());
        m.erase(*(m.begin()));
        
        m.insert(first + second);
        k--;
    }
    printf("%d",*(m.begin()));
    return 0;
}


