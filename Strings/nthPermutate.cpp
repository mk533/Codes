/*nth lexogrphical premutation of string*/

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int main()
{
    string S;
    cin >> S;
    
    cout<<S<<endl;
    cout<<"---------"<<endl;
    sort(S.begin(),S.end());
    cout<<S<<endl;
    cout<<"---------"<<endl;
    int n;
    cin>>n;
    int i = 1;
    do
    {
        if(i == n)
            break;
        i++;
    }while(next_permutation(S.begin(),S.end()));
    
    cout<<S <<endl;
    return 0;
}
