/* Generate binary numbers till n */

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<queue>

using namespace std;

int main()
{
    int n;
    string temp;
    
    printf("Enter n\n");
    scanf("%d",&n);
    
    queue <string> Q;
    
    Q.push("1");
    
   
    
    while(n--)
    {
        temp = Q.front();
        Q.pop();
        cout<<temp<<"  ";
        Q.push(temp + "0");
        Q.push(temp + "1");
    }
    
    
    
    return 0;
}
