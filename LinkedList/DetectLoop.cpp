


//Tortoise and hare method, if both meet at some point loop exists
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
    //making loop in linked list
    struct node *cur = head;
    while( cur -> next) {
        cur = cur -> next;
    }
   cur->next = head; //comment and check for loop not exist case
  //  Print(head); // if it goes to Infinte loop then its working
    struct node *slow = head;
    struct node *fast = head;
    int flag = 0;
    if(head) {
        while( fast && fast->next) {
            slow  = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast)
            {
                flag = 1;
                break;
            }
            
        }
        printf(flag == 0 ? "Loop not Exists" : "Loop Exist");
    }
    return 0;
}



