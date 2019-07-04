/*Printing Leaves from left  in Binary Tree*/

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
    struct node *root = NewNode(1);
    root -> left = NewNode(2);
    root -> right = NewNode(3);
    root -> left -> left = NewNode(4);
    root -> right -> left = NewNode(5);
    root -> right -> right = NewNode(8);
    root -> right -> left -> left = NewNode(6);
    root -> right -> left -> right = NewNode(7);
    root -> right -> right -> left = NewNode(9);
    root -> right -> right -> right = NewNode(10);
    
   
    
    Leaves(root);
    printf("\n");
   
}


