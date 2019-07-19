/*Lexogrphical Largest Substring*/

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
    string res = "";
    for(int i =  0 ; i < S.length(); i++) {
        res = max(res,S.substr(i));
    }
    cout<<res;
    return 0;
}

