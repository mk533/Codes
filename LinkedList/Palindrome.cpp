/*
 Check Linked List in palindrome or not
 Method 1:- using Stack , requires two traversals of linked list O(n) space.
 Method 2:- traverse till middle node (Hare and Torotoise)
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

struct node* Reverse(struct node **head)
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
   
    
    return prev;
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
    int len = Length(head);
    
    if(len == 1)
    {
        printf("Palindrome\n");
        return 0;
    }
    
    
    struct node *slow = head;
    struct node *fast = head;
    struct node *prev = NULL;
    if(head) {
        while( fast && (fast -> next) ) {
            prev = slow;
            slow  = slow -> next;
            fast = fast -> next -> next;
        }
    }
    if(prev)
    prev->next = NULL;
    //struct node *temp = Reverse(&slow);
    
    
    struct node *first = head;
    struct node *second = NULL;
    
    if( len % 2 ){
        if(slow)
            slow = slow->next;
    }
    
    
    second = slow;
    
   Print(first);
    //Print(second);
    
    struct node *temp = Reverse(&second);
    Print(temp);
    int flag = 0;
    while(first && temp)
    {
        if(first -> data != temp -> data)
        {
            flag = 1;
            break;
        }
        first =  first -> next;
        temp = temp -> next;
    }
    printf(flag == 0 ?"Palindrome\n" : "Not Palindrome\n");
    
    return 0;
}





