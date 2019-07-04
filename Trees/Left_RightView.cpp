
/*Left and Right View Binary Tree without using queue*/


#include<cstdio>
#include<cstdlib>
#include<climits>

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

void LeftView(struct node *root,  int level, int *max)
{
    if(!root)
        return;
    
    if( *max < level) {
        printf("%d ", root -> data);
        *max = level;
    }
    
    LeftView(root -> left,level+1,max);
    LeftView(root -> right,level+1,max);
    
}
void RightView(struct node *root,  int level, int *max)
{
    if(!root)
        return;
    
    if( *max < level) {
        printf("%d ", root -> data);
        *max = level;
    }
    
    RightView(root -> right,level+1,max);
    RightView(root -> left,level+1,max);
    
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
    
    int max = INT_MIN;
    LeftView(root,1,&max);
    printf("\n");
    int max1 = INT_MIN;
    RightView(root,1,&max1);
    
}



