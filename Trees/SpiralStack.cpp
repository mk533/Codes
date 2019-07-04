
/* Spiral Level order traversal using Stack*/

#include<cstdio>
#include<cstdlib>
#include<stack>

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



void LevelOrder(struct node *root)
{
    if( !root )
        return;
    stack <struct node *> S1;
    stack <struct node *> S2;
    struct node *temp = NULL;
    
    S1.push(root);
    
    while(!S1.empty() || !S2.empty()) {
        
        while(!S1.empty()) {
            temp = S1.top();
            S1.pop();
            printf("%d ",temp -> data);
            
            if (temp -> left)
                S2.push( temp -> right);
            if (temp -> right)
                S2.push(temp -> left);
        }
        printf("\n");
        while(!S2.empty()) {
            temp = S2.top();
            S2.pop();
            printf("%d ",temp -> data);
            
            if (temp -> left)
                S1.push( temp -> left);
            if (temp -> right)
                S1.push(temp -> right);
        }
        printf("\n");
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
    
    LevelOrder(root);
    
    return 0;
}

/*  1
  /   \
 2      3
/  \   /  \
7   6 5    4

 */





