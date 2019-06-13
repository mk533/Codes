

/*Segregate Even and Odd Nodes in Linked List
 step 1:- go to last node
 step 2:- move odd nodes  to end (Order is Maintained)
 */

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

void Segregate(struct node **head)
{
    struct node *last = NULL;
    struct node *cur = *head;
    struct node *prev = NULL;

    while (cur ->next) {
        cur = cur ->next;
    }
    last = cur;
    struct node * new_last = last;
    cur = *head;
    
    
        while( cur -> data % 2 != 0   && cur != last) // moving all odd nodes to end.
        {
            new_last -> next = cur;
            cur = cur -> next;
            new_last -> next -> next = NULL;
            new_last = new_last -> next;
        }
        
        *head = cur; // making first Even Node as Head
    
        if(cur -> data %2 == 0) // moving all odd nodes to end which comes after even nodes
        {
            cur = *head;
            while(cur != last)
            {
                if(cur -> data %2 == 0){
                    prev = cur;
                    cur = cur -> next;
               }
                else{
                    prev -> next = cur -> next;
                    cur -> next = NULL;
                    new_last -> next = cur;
                    new_last = new_last -> next;
                    cur = prev->next;
                }
            }
        }
        else
        {
            prev = cur;
        }
    if(new_last != last && (last -> data) % 2 != 0 ) // move last odd node to end
    {
        prev -> next  = last -> next;
        new_last -> next = last;
        last -> next = NULL;
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
    Segregate(&head);
    Print(head);
    
    return 0;
}





