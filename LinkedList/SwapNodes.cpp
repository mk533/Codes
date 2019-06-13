

// Swapping Node Links of Linked List
// Asumming Swapping nodes present in Linked List

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

struct node *Find_prev(struct node *head, int val)
{
    struct node *prev = NULL;
    struct node *cur = head;
    
    while(cur && cur -> data != val)
    {
        prev = cur;
        cur = cur -> next;
    }
    return prev;
}
int main()
{
    struct node *head = NULL;
    int n;
    printf("\nEnter no of nodes in Linked List\n");
    scanf("%d",&n);
    
    
    
    while(n--) {
        int val;
        scanf("%d",&val);
        head = Insert_end(head,val);
    }
    Print(head);
    
    int p,q;
    printf("Enter two values \n");
    scanf("%d %d",&p,&q);
    
    struct node *first = Find_prev(head,p);
    struct node *second = Find_prev(head,q);
    
    struct node *cur_p = first->next;
    struct node *cur_q = second->next;
    
    if(first != NULL)
       first -> next = cur_q;
    else
        head = cur_q;
        
    if(second != NULL)
        second -> next = cur_p;
    else
        head = cur_p;
    
    struct node *temp = NULL;
    
    temp = cur_q->next;
    cur_q->next = cur_p -> next;
    cur_p ->next = temp;
    
    Print(head);
    
    return 0;
}




