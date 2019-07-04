
/*Level order traversal using Queue*/

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


void LevelOrder(struct node *root)
{
    if( !root )
        return;
    queue<struct node* > Q;
    struct node *temp = NULL;
    
    Q.push(root);
    Q.push(NULL); // Delimiter
    
    while( !Q.empty() ) {
        
        temp = Q.front();
        Q.pop();
        if( temp ) {
            printf("%d ",temp->data);
            if(temp -> left) {
                Q.push(temp -> left);
            }
            if(temp -> right) {
                Q.push(temp -> right);
            }
        }
        else
        {
            printf("\n");
           if(!Q.empty())
            Q.push(NULL);
        }
    }
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
    
    
    LevelOrder(root);
    return 0;
}
/*
     1
   /   \
  2     3
 /  \    \
4    5    6
 
 */


