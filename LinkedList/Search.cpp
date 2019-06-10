
//searching an element in Linked list using Recursive and Iterative method
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
void DeleteLL(struct node **head)
{
    struct node *cur = *head;
    struct node *next = NULL;
    
    while(cur)
    {
        next = cur -> next;
        free(cur);
        cur = next;
    }
    *head = NULL;
    
}
int Search(struct node *head, int ele)
{
    if(!head)
        return 0;
    if(head -> data == ele)
        return 1;
    return Search(head -> next,ele);
}

int Search_Iter(struct node *head, int ele)
{
    struct node *cur = head;
    while(cur)
    {
        if(cur -> data ==  ele)
            return 1;
        cur = cur -> next;
    }
    return 0;
}

int main()
{
    struct node *head = NULL;
    struct node *cur;
    int n;
    printf("\nEnter no of nodes in Linked List\n");
    scanf("%d",&n);
    
    while(n--) {
        int val;
        scanf("%d",&val);
        head = Insert_end(head,val);
    }
    Print(head);
    
    printf("Enter the element to be search\n");
    int ele;
    scanf("%d",&ele);
    
    printf(Search(head,ele) == 1 ? "Element Found \n" :  "Not Found\n");
    
   // printf(Search_Iter(head,ele) == 1 ? "Element Found \n" :  "Not Found\n");
    
}


