

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

struct node* SortedMerge(struct node *head1, struct node *head2)
{
    if( !head1 )
        return head2;
    if( !head2)
        return head1;
    struct node *final_head = NULL;
    
    if( head1 -> data <= head2  -> data)
    {
        final_head = head1;
        final_head -> next = SortedMerge(head1 -> next, head2);
    }
    else {
        final_head = head2;
        final_head -> next = SortedMerge(head1, head2 ->next);
    }
    return final_head;
}
int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    int n,m;
    printf("\nEnter no of nodes in Sorted Linked List 1\n");
    scanf("%d",&n);
    
    
    
    while(n--) {
        int val1;
        scanf("%d",&val1);
        head1 = Insert_end(head1,val1);
    }
    Print(head1);
    
    printf("\nEnter no of nodes in Sorted Linked List 2\n");
    scanf("%d",&m);
    
    
    
    while(m--) {
        int val2;
        scanf("%d",&val2);
        head2 = Insert_end(head2,val2);
    }
    Print(head2);
    
    struct node *head = SortedMerge(head1,head2);
    
    Print(head);
    return 0;
}





