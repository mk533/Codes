/* balanced parentheses in an expression */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<stack>


using namespace std;

int main()
{
    stack<char> S;
    string str;
    cin>>str;
    
    int flag = 0;
    
    for (int  i = 0 ; i < str.length() ; i++) {
        
        if( str[i] == '(' ||  str[i] == '{' || str[i] == '[')
        {
            S.push(str[i]);
            continue;
        }
        if(S.empty())
        {
            flag = 1;
            break;
        }
        else
        {
            if( str[i] == '}')
            {
                if( S.top() == '(' || S.top() == '[')
                {
                    flag = 1;
                    break;
                }
                else
                    S.pop();
            }
            
           else  if( str[i] == ')')
            {
                if( S.top()== '{' || S.top() == '{')
                   {
                       flag = 1;
                       break;
                   }
                else
                    S.pop();
            }
            
            else if( str[i] == ']')
            {
                if( S.top() == '(' || S.top() == '{')
                {
                    flag = 1;
                    break;
                    
                }
                else
                    S.pop();
            }
        }
        
    }
    if( !S.empty() || flag == 1)
        printf("No\n");
    else
        printf("Yes\n");
        
    return 0;
}
