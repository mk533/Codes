/*Boundary traversal of Tree*/

#include<cstdio>
#include<cstdlib>

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
void LeftBoundary(struct node *root)
{
    if(!root)
        return;
    struct node *temp = root;
    
    while(temp) {
        if(temp -> left != NULL || temp -> right != NULL) {
            printf("%d ", temp -> data);
        }
        if( temp -> left) {
            temp = temp -> left;
        }
        else{
                temp = temp -> right;
        }
    }
}
void RightBoundary(struct node *root)
{
    if(!root)
        return;
    
    if(root->right) {
        RightBoundary( root-> right);
        if(root -> left != NULL || root -> right != NULL) {
            printf("%d ",root -> data);
        }
    }
    else {
        RightBoundary(root -> left);
        if(root -> left != NULL || root -> right != NULL) {
            printf("%d ",root -> data);
        }
    }
}
void Leaves(struct node *root)
{
    if(!root)
        return;
    if(root -> left == NULL && root -> right == NULL) {
        printf("%d ",root -> data);
    }
    Leaves(root -> left);
    Leaves(root -> right);
}
int main()
{
    struct node* root = NewNode(20);
    root -> left = NewNode(8);
    root -> left -> left = NewNode(4);
    root -> left -> right = NewNode(12);
    root -> left -> right -> left = NewNode(10);
    root -> left -> right -> right = NewNode(14);
    root -> right = NewNode(22);
    root -> right -> right = NewNode(25);
    
    LeftBoundary(root);
   // printf("\n");
    Leaves(root -> left); // iterative
   // printf("\n");
    Leaves(root -> right);
   // printf("\n");
    RightBoundary(root->right); // Recursive
}

