/* print all subsets of  string*/

#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iostream>

using namespace std;

void Subset(vector<string> &V,string S)
{
    int N = S.length();
    string temp;
    for(int i = 0 ; i < (1 << N); i++) {
        
        string temp;
       
        for(int j = 0 ;j < N; j++) {
            if(i & 1 << j) {
               // printf("%c ",S[j]);
                temp = temp + S[j];
            }
        }
        if(temp.length()>=1)
            V.insert(V.begin(),temp);
      //  printf("\n");
    }
    
}
bool compare(string s1,string s2) {
    return s1.length() < s2.length();
}
void Print(vector<string> V)
{
    for(int i = 0; i < V.size(); i++) {
        cout<<V[i]<<endl;
    }
    printf("\n");
}
int main()
{
    string S;
    vector<string> V;
    
    cin >> S;
    
    Subset(V,S);
    //Print(V);
   printf("%lu",V.size());
    sort(V.begin(),V.end(),compare);
    reverse(V.begin(),V.end());
    Print(V);
    return 0;
}
