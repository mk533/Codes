
// Multiply two  numbers represented in Linked List


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
long long Multiply(struct node *head1,struct node *head2)
{
    long long int m = 0 ,n = 0,sign = 1;
    
    if( !head1  || !head2)
        return 0;
    struct node *cur ;
    
    cur = head1;
    
    if(head1 ->data < 0 )
    {
        sign *= -1;
        head1->data = abs(head1->data);
    }
        if(head2->data <0)
        {
            sign *= -1;
            head2->data = abs(head2->data);
        }
    while(cur)
    {
        m = (m * 10) + cur->data;
        cur = cur -> next;
    }
   // printf("m = %lld \n",m);
    cur = head2;
    while(cur)
    {
        n = (n * 10) + cur->data;
        cur = cur -> next;
    }
    //printf("m = %lld \n",n);
    return ( sign * m * n );
}
int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    int n,m;
    printf("\nEnter no of nodes in Linked List 1\n");
    scanf("%d",&n);
    
    
    
    while(n--) {
        int val1;
        scanf("%d",&val1);
        head1 = Insert_end(head1,val1);
    }
    Print(head1);
    
    printf("\nEnter no of nodes in  Linked List 2\n");
    scanf("%d",&m);
    
    
    
    while(m--) {
        int val2;
        scanf("%d",&val2);
        head2 = Insert_end(head2,val2);
    }
    printf("%lld\n",Multiply(head1,head2));
    
    return 0;
}





