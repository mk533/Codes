

/*Diametre of a  Binary Tree*/

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
int max(int a, int b)
{
    return a > b ? a : b;
}
int Height(struct node *root)
{
    if(!root)
        return 0;
    
    if(root -> left == NULL && root -> right == NULL)
        return 1;
    
    return 1 + max(Height(root -> left),Height(root -> right));
}

int Diameter(struct node *root)
{
    if(!root)
        return 0;
    int left_height = Height(root -> left);
    int right_height = Height(root -> right);
    
    int left_diameter = Diameter(root -> left);
    int right_diameter = Diameter(root -> right);
    
    return max(left_height + right_height + 1 , max(left_diameter,right_diameter));
    
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
    
    printf("%d\n",Diameter(root));
    return 0;
}

