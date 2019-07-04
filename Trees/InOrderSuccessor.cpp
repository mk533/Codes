/*Inorder Successor of every node*/

#include<cstdio>
#include<cstdlib>

using namespace std;


struct node {
    int data;
    struct node *left;
    struct node *right;
    struct node *next;
};

struct node *NewNode(int i)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node ));
    temp -> data = i;
    temp -> next = NULL;
    temp -> left = NULL;
    temp -> right = NULL;
    
    return temp;
}

void Inorder(struct node* root)
{
    if (!root)
        return;
    
    Inorder(root->left);
    printf("%d ",root -> data);
    Inorder(root -> right);
}

void InorderSuccessor(struct node* root)
{
    if (!root)
        return;
    
    InorderSuccessor(root -> left);
    if(root -> next)
    {
        printf("next of %d is %d \n",root -> data,root -> next -> data);
       // printf("%d-->",root -> data);
    }
    else
        printf(" NULL ");
    InorderSuccessor(root -> right);
}

void PopulateSuccessor(struct node *root)
{
    static struct node *temp = NULL;
    if(!root)
        return;
    PopulateSuccessor(root -> right);
    root -> next = temp;
    temp = root;
    PopulateSuccessor(root -> left);
}
int main()
{
    struct node *root = NULL;
    
    root = NewNode(1);
    root -> left = NewNode(2);
    root -> right = NewNode(3);
    root -> left -> left = NewNode(4);
    root -> left -> right = NewNode(5);
    root -> right -> right  = NewNode(6);
    
    printf("Inorder Traversal of tree is \n");
    Inorder(root);
    printf("\n----------------\n");
    PopulateSuccessor(root);
    
    InorderSuccessor(root);
    return 0;
}
/*
              1
            /   \
           2     3
         /  \     \
        4    5     6
 */
