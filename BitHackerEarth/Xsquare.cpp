#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int T;
    
    
    scanf("%d", &T);
    
    while(T--) {
        string temp1;
        string temp2;
        int A[26] = {0};
        int B[26] = {0};
        
        cin>>temp1;
        cin>>temp2;
        for(int j = 0; j < temp1.length(); j++) {
            A[temp1[j] - 'a'] = 1;
        }
        
        for(int j = 0; j < temp2.length(); j++) {
            B[temp2[j] - 'a'] = 1;
        }
        
        int flag = 0;
        
        for(int i = 0; i < 26; i++) {
            // printf("%d %d",A[i],B[i]);
            if(A[i] == 1 && A[i] == B[i]) {
                flag = 1;
                break;
            }
            // printf("\n");
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
        
    }
    
    
    
    return 0;
}

