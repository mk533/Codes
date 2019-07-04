
/*Path from Root to given Node in Binary Tree*/

#include<cstdio>
#include<cstdlib>
#include<vector>

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
bool Path(struct node *root,vector<int> &V,int n)
{
    if(!root)
        return false;
    V.push_back(root -> data);
    
    if(root -> data == n)
        return true;
    
    if( Path(root -> left,V,n) || Path(root -> right,V,n) )
        return true;
    
    V.pop_back();
    
    return false;
}
int main()
{
    struct node * root = NewNode(1);
    root -> left = NewNode(2);
    root -> right = NewNode(3);
    root -> left -> right = NewNode(4);
    root -> left -> right -> right = NewNode(5);
    root -> left -> right -> right -> right = NewNode(6);
    
    vector<int> V;
    if( Path(root,V,6) ) {
        for(int i = 0 ; i < V.size(); i++) {
            printf("%d ",V[i]);
        }
     }
    printf("\n");
    return 0;
}
