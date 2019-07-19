
/*Sort according to frequency of elements*/
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>

using namespace std;

void Print(vector<int> A)
{
    
    for (int i = 0;  i < A.size() ; i++) {
        cout<< A[i] <<" ";
    }
    printf("\n--------------------\n");
    
}

int MAX(int a, int b)
{
    return a > b ? a : b;
}
bool comp(pair<int,int> a, pair<int,int> b)
{
    if(a.second != b.second)
        return a.second > b.second;
    else
        return a.first < b.first;
    
}
int main()
{
    int n;
    vector<int> A;
    
    printf("Enter n \n");
    scanf("%d",&n);
    
    for (int i = 0;  i < n ; i++) {
        int p;
        cin>>p;
        A.push_back(p);
    }
    Print(A);
    
    map <int,int > M;
    map <int,int>::iterator it;
    
    
    for (int i = 0;  i < n ; i++) {
        it = M.find(A[i]);
        
        if(it == M.end() )
        {
            M.insert(make_pair(A[i],1));
        }
        else
        {
            int temp = it -> second;
            temp++;
            M.erase(it);
            M.insert(make_pair(A[i],temp));
        }
    }
   
    vector<pair<int, int> > V;
   
    for (it = M.begin() ; it!= M.end(); it++) {
        V.push_back(make_pair(it->first,it->second));
    }
    
    for (int i = 0 ; i< V.size(); i++)
    {
        printf("%d--> %d \n",V[i].first, V[i].second);
    }
    
    printf("-----------------------\n");
    
    sort(V.begin(),V.end(),comp);
    
    for (int i = 0 ; i< V.size(); i++)
    {
        printf("%d--> %d \n",V[i].first, V[i].second);
    }
    return 0;
}
    
    





