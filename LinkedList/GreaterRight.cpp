
// remove all the nodes which have a greater value on right side.
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

int Length(struct node *head)
{
    if(!head)
        return 0;
    
    return 1 + Length(head -> next);
}

void Reverse(struct node **head)
{
    struct node *cur = *head;
    struct node *prev = NULL;
    struct node *next = *head;
    
    while(cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        
    }
    *head = prev;
}
void GreaterRight(struct node *head)
{
    if(!head)
        return;
    struct node  *present_max = head ;
    
    
    struct node *cur = NULL;
    struct node *temp;
    cur = head->next; ;
    
    while(cur)
    {
        if(cur->data < present_max->data )
        {
            
            present_max -> next = cur -> next;
            temp = cur;
            cur = cur->next;
            free(temp);
        }
        else
        {
            present_max  = cur;
            cur = cur ->next;
        }
    }
}
int main()
{
    struct node *head = NULL;
    int n;
    int count = 1;
    printf("\nEnter no of nodes in Linked List\n");
    scanf("%d",&n);
    
    while(n--) {
        int val;
        scanf("%d",&val);
        head = Insert_end(head,val);
    }
    Print(head);
    printf("----------------------\n");
    Reverse(&head);
   // Print(head);
    //printf("----------------------\n");
    GreaterRight(head);
    Reverse(&head);
    Print(head);
    
    return 0;
}




