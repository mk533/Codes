
/*Subsequence of string*/

#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>

using namespace std;

void Subsequence(set<string> &S, string str)
{
    if(str.length() == 0)
        return;
    
    if(S.find(str) == S.end())
        S.insert(str);
    
    for (int i = 0 ; i < str.length(); i++) {
        string temp = str;
        temp.erase(i,1);
        Subsequence(S,temp);
    }
}
int main()
{
    string str;
    cin >> str;
    
    cout<<str<<endl;
    cout<<"---------"<<endl;
    
    
    set<string> S;
    
    Subsequence(S,str);
    
    set<string> :: iterator it;
    for(it = S.begin(); it != S.end(); it++ ) {
        cout<<*it<<endl;
    }
    return 0;
}


