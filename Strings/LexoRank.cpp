/*Lexogrphical Rank of String*/

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
    
    string temp = S;
    sort(temp.begin(),temp.end());
    int count = 1;
    do
    {
        if(S.compare(temp) == 0)
            break;
        count++;
        
    }while(next_permutation(temp.begin(),temp.end()));
    
    cout<<count;
    return 0;
}


