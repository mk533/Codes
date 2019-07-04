/*Insertion into BST Tree*/

#include<cstdio>
#include<cstdlib>
#include<climits>

using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *NewNode(int data)
{
    struct node  *temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;
    
    return temp;
}

void Inorder(struct node *root)
{
    if(!root)
        return;
    
    Inorder(root -> left);
    printf("%d ",root -> data);
    Inorder(root -> right);
}

struct node* insert(struct node *root, int n)
{
    if(!root)
        return NewNode(n);
    if(root -> data > n)
        root -> left = insert(root -> left, n);
    else if(root -> data < n)
        root -> right = insert(root -> right, n);
        
    
        return root;
    
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    
    Inorder(root);
    
    return 0;
}
