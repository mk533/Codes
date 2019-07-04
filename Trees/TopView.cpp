/*Top View of Binary Tree*/

#include<cstdio>
#include<cstdlib>
#include<map>
#include<queue>

using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* NewNode(int data)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    
    temp -> data = data;
    temp -> right = NULL;
    temp -> left = NULL;
    
    return temp;
}
void TopView(struct node *root)
{
    if(!root)
        return;
    queue < pair<int,struct node *> > Q;
    map <int, int > M;
    int index = 0;
    pair <int, struct node*> P;
    
    P.first = index;
    P.second = root;
    Q.push(P);
   // M[index].push_back(root -> data);
    
    while(!Q.empty()) {
        P = Q.front();
        Q.pop();
        
        if(M.find ( (P.first)) == M.end()) {
            printf("%d ",(P.second ) -> data );
            M[(P.first)] = (P.second) -> data;
        }
        if( (P.second) -> left ) {
            Q.push(make_pair(P.first - 1,(P.second) -> left));
        }
        if( (P.second) -> right ) {
            Q.push(make_pair(P.first + 1,(P.second) -> right));
        }
    }
}
int main()
{
    struct node * root = NewNode(1);
    root -> left = NewNode(2);
    root -> right = NewNode(3);
    root -> left -> right = NewNode(4);
    root -> left -> right -> right = NewNode(5);
    root -> left -> right -> right -> right = NewNode(6);
    
    TopView(root);
    printf("\n");
    return 0;
}
