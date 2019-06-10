

//Middle node of Linked List   -> traverse till n/2 node
//                             -> Hare and Tortoise Method
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
    
 /*
    int len = Length(head);
    struct node *cur = head;
    int temp  = len/2;
    
    while( temp--) {
        cur = cur -> next;
    }
    printf("Middle node of Linked List is %d\n",cur -> data);
  */
    struct node *slow = head;
    struct node *fast = head;
    if(head) {
        while( fast && (fast -> next) ) {
            slow  = slow -> next;
            fast = fast -> next -> next;
        }
    printf("Middle node of Linked List %d \n",slow->data);
    }
    
}



