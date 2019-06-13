// Merge Sort of Linked List

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

void Split(struct node *head, struct node **first, struct node **second)
{
   // Print(head);
    //printf("\n------------------------------------\n");
    
    if (head == NULL || head->next == NULL)
    {
        *first = head;
        *second = NULL;
        return;
    }
    
    struct node* slow = head;
    struct node* fast = head -> next;
    
    // Advance 'fast' two nodes, and advance 'slow' one node
    while (fast != NULL)
    {
        fast = fast -> next;
        if (fast != NULL)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
    }
    // slow is not middle node here, its node before middle node,
    
    *first = head;
    *second = slow -> next;
    slow -> next = NULL;
    
}
void MergeSort(struct node **head)
{
    if(*head == NULL || (*head)->next == NULL )
        return ;
    struct node *a = NULL;
    struct node *b = NULL;
   
    
    Split(*head,&a,&b);   // split head into two lists
    
    MergeSort(&a); // recursively sorting 1st list
    
    MergeSort(&b); // recursively sorting 2nd list
    
    *head = SortedMerge(a,b); // Merge two lists
    
    
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
    MergeSort(&head);
    Print(head);
    return 0;
}




