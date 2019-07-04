
/*Vertical Order of  Binary Tree*/

#include<cstdio>
#include<cstdlib>
#include<map>
#include<vector>
#include<queue>

using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *NewNode(int i)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = i;
    temp -> left = NULL;
    temp -> right = NULL;
    
    return temp;
}

void Vertical(struct node *root) {
    
    if(!root)
        return;
    
    map< int,vector <int> > M;
    queue < pair <struct node*,int> > Q;
    int temp = 0;
    
    Q.push(make_pair(root,temp));
   
    while( !Q.empty() ) {
       
        pair <struct node *,int> P;
        P = Q.front();
        Q.pop();
        
        M[P.second].push_back( (P.first) -> data);
        
        if( (P.first) -> left ) {
            Q.push(make_pair((P.first) -> left ,P.second - 1));
        }
        
        if( (P.first) -> right ) {
            Q.push(make_pair( (P.first) -> right ,P.second + 1));
        }
    }
    
    map < int, vector<int> > :: iterator it;
    
    for(it = M.begin(); it!= M.end(); it++) {
        for(int i = 0 ; i < it -> second.size(); i++) {
            printf("%d ",it -> second[i] );
        }
        printf("\n");
    }
}
void Vertical2(struct node * root,int index,map<int, vector<int> > &M)
{
    if(!root)
        return;
    M[index].push_back(root -> data);
    
    Vertical2(root -> left, index - 1,M);
    
    Vertical2(root -> right, index + 1,M);
}
int main()
{
    struct node *root = NewNode(1);
    root -> left = NewNode(2);
    root -> right = NewNode(3);
    root -> left -> left = NewNode(4);
    root -> left -> right = NewNode(5);
    root -> right -> left = NewNode(6);
    root -> right -> right = NewNode(7);
    root -> right -> left -> right = NewNode(8);
    root -> right -> right -> right = NewNode(9);
    
    
    //Vertical(root);// not efficient
    map <int , vector<int> > m;
    Vertical2(root,0,m);
    
    map < int, vector<int> > :: iterator it;
    
    for(it = m.begin(); it!= m.end(); it++) {
        for(int i = 0 ; i < it -> second.size(); i++) {
            printf("%d ",it -> second[i] );
        }
        printf("\n");
    }
    printf("\n");
    
}


