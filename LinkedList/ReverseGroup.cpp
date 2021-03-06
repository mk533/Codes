
// Reverse of Linked List
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

struct node* Reverse(struct node *head, int k)
{
    struct node *cur = head;
    struct node *prev = NULL;
    struct node *next = head;
    int count = 0;
    while(cur && count < k)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        count++;
    }
    if( next != NULL)
        (head)->next = Reverse(next,k);
    
    return prev;
}
int main()
{
    struct node *head = NULL;
    int n;
    printf("\nEnter no of nodes in Linked List\n");
    scanf("%d",&n);
    
    struct node *temp = NULL;
    
    while(n--) {
        int val;
        scanf("%d",&val);
        head = Insert_end(head,val);
    }
    Print(head);
    
    printf("Enter group size\n");
    int k;
    scanf("%d",&k);
    
    head = Reverse(head,k);
    Print(head);
    return 0;
}




