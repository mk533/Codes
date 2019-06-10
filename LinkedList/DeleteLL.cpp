//Deleting  Complete Linked List
//use previous pointer and use it while deleting
//update prev and cur pointer in every iteration
#include<cstdio>
#include<cstdlib>

using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *NewNode(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = val;
    temp -> next = NULL;
    
    return temp;
}
struct node *Insert_end(struct node *head,int val)
{
    if(!head)
    {
        head = NewNode(val);
    }
    else
    {
        struct node *cur = head;
        
        while(cur -> next) {
            cur = cur -> next;
        }
        cur->next = NewNode(val);
        
    }
    return head;
    
}
void Print(struct node *head)
{
    struct node *cur = head;
    
    while(cur) {
        printf("%d-->",cur -> data);
        cur = cur->next;
    }
    printf("NULL\n\n");
}
void DeleteLL(struct node **head)
{
    struct node *cur = *head;
    struct node *next = NULL;
    
    while(cur)
    {
        next = cur -> next;
        free(cur);
        cur = next;
    }
    *head = NULL;
    
}

int main()
{
    struct node *head = NULL;
    struct node *cur;
    int n;
    printf("\nEnter no of nodes in Linked List\n");
    scanf("%d",&n);
    
    while(n--) {
        int val;
        scanf("%d",&val);
        head = Insert_end(head,val);
    }
    Print(head);
    
    DeleteLL(&head);
    
    Print(head);
}


