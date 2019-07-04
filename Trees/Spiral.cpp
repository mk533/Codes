
/*Spiral Level order traversal */

#include<cstdio>
#include<cstdlib>
#include<queue>

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
int max(int a, int b)
{
    return a > b ? a : b;
}
void Inorder(struct node* root)
{
    if (!root)
        return;
    
    Inorder(root->left);
    printf("%d ",root -> data);
    Inorder(root -> right);
}

int Height(struct node *root)
{
    if (!root)
        return 0;
    return 1 + max(Height(root->left),Height(root->right));
}


void LevelOrder(struct node *root,int l,bool flag)
{
    int count = 1 ;
    
    if(!root || count < 0)
        return;
    if(count == l)
        printf("%d ",root -> data);
    l--;
    if( flag ) {
        LevelOrder(root -> left,l,flag);
        LevelOrder(root -> right,l,flag);
    }
    else {
         LevelOrder(root -> right,l,flag);
         LevelOrder(root -> left,l,flag);
    }
}
int main()
{
    struct node *root = NULL;
    
    root = NewNode(1);
    root -> left = NewNode(2);
    root -> right = NewNode(3);
    root -> left -> left = NewNode(7);
    root -> left -> right = NewNode(6);
    root -> right -> left = NewNode(5);
    root -> right -> right = NewNode(4);

    
    printf("Inorder Traversal of tree is \n");
    Inorder(root);
    printf("\n----------------\n");
    
    int height  = Height(root);
    bool flag = false;
    for (int i = 1; i <= height; i++) {
         LevelOrder(root,i,flag);
         flag = !flag;
        printf("\n");
    }
   
    return 0;
}

/*      1
     /   \
   2      3
 /  \   /  \
7    6 5    4
 
 */



