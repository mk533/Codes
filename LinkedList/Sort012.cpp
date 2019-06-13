// Sort 0,1,2 in unsorted Linked List
// using 3 dummy node n pointers

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

struct node* Sort012(struct node *head)
{
    if(!head)
        return head;
    struct node *zero = NewNode(0);
    struct node *one = NewNode(0);
    struct node *two = NewNode(0);
    
    struct node *cur = head;
    struct node *Z = zero;
    struct node *O = one;
    struct node *T = two;
    
    while(cur)
    {
        if( cur -> data == 0)
        {
            Z -> next = cur;
            Z = Z-> next;
        }
        else if(cur -> data == 1)
        {
            
            O -> next = cur;
            O = O -> next;
        }
        else
        {
            T -> next = cur;
            T = T -> next;
        }
        cur = cur -> next;
        
    }
    
    Z-> next = one->next ? one->next : two->next ;
    O -> next = two -> next;
    T ->next = NULL;
    
    return zero->next;
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
    
    head = Sort012(head);
    
    Print(head);
    
}



