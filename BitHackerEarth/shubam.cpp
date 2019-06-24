
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    
    while( T-- ) {
        int n;
        cin>>n;
        string S;
        cin>>S;
        int count = 0;
        for(int i = 0 ;i < n; i++) {
            if(S[i] == '0') {
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}



