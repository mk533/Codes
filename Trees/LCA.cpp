
/*LCA of two nodes in Binary Tree*/

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

struct node *LCA(struct node *root, int n1,int n2)
{
    if(!root)
        return NULL;
    
    if(root -> data == n1 || root -> data == n2)
        return root;
    
    struct node *left = LCA(root -> left,n1,n2);
    struct node *right = LCA(root -> right,n1,n2);
    
    if( left && right )
        return root;
    
    return (left != NULL) ? left : right;
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
    
    int n1;
    int n2;
    
    scanf("%d%d",&n1,&n2);
    printf("LCA of %d %d is %d\n",n1,n2,LCA(root,n1,n2) -> data);
    return 0;
}

