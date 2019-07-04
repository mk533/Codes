/*Inorder Successor of given node*/

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
    struct node *temp = (struct node *)malloc(sizeof(struct node ));
    
    temp -> data = i;
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
int LeftMost(struct node *temp)
{
    struct node *cur = temp;
    
    while(cur && cur -> left) {
        cur = cur -> left;
    }
    return (cur -> data);
}
void InorderSuccessor(struct node *root, struct node *temp)
{
    if ( temp -> right ) {
        printf("Inorder Successor of %d is %d \n",LeftMost(temp->right));
    }
    if
    
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
    
    InorderSuccessor(root,root);
    
    InorderSuccesor(root, root -> right);
    
    InorderSuccesor(root, root -> left -> left);
    
    // case 3
    inorderSuccesor(root, root->right->right);
    return 0;
}
/*
      1
    /   \
   2     3
  /  \     \
4    5     6

 */

