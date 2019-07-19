/*Lexographically Minimum in String Rotation*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int main()
{
    string S;
    
    cin>>S;
    
    //cout<< S << endl;
    cout<< S.length() <<endl;
    string temp = S;
    string min = S;
    temp.append(S);
   // cout<< temp << endl;
    
    for (int i = 0 ; i < S.length(); i++) {
        cout<< i <<"-->";
        cout << temp.substr(i,S.length()) << endl;
        
        if(min.compare(temp.substr(i,S.length())) > 0  ) {
            min = temp.substr(i,S.length());
        }
    }
    cout<<"--------------"<<endl;
    cout<<min;
}
