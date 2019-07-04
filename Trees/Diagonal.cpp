/*Diagonal traversal of Tree*/
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
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = i;
    temp -> left = NULL;
    temp -> right = NULL;
    
    return temp;
}
void PrintQ(queue<struct node*> q)
{
     while(!q.empty()) {
         printf("%d ",q.front()->data);
         q.pop();
     }
    printf("\n------------\n");
}
void Diagonal(struct node* root)
{
    if(!root)
        return;
    
    struct node *temp = root;
    queue<struct node*> Q;
    
    while( temp ) {
        Q.push(temp);
        temp = temp -> right;
    }
   // PrintQ(Q);
    Q.push(NULL);
    while(!Q.empty()) {
        temp  = Q.front();
        Q.pop();
        if(temp) {
           printf("%d ",temp->data);
            if(temp -> left) {
                Q.push( temp -> left );
                temp = temp -> left;
                while(temp -> right)
                {
                    temp = temp -> right;
                    Q.push( temp );
                }
            }
        }
        else
        {
            if(!Q.empty()){
                //PrintQ(Q);
                Q.push(NULL);
                
            }
            printf("\n");
        }
       
    }
    
}

int main()
{
    struct node *root = NewNode(8);
    root -> left = NewNode(3);
    root -> right = NewNode(10);
    root -> left -> left = NewNode(1);
    root -> left -> right = NewNode(6);
    root -> right -> right = NewNode(14);
    root -> right -> right -> left = NewNode(13);
    root -> left -> right -> left = NewNode(4);
    root -> left -> right -> right = NewNode(7);
    
    Diagonal(root);
    
}
