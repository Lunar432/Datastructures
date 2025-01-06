#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node * insertVal(struct node *head,int position,int item)
{
  struct node *newNode;
  newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = item;
  newNode->next = NULL;
  if(position==0){
    newNode ->next = head;
    head = newNode;
    return head;
  }
  else{
  struct node *temp,*current = head;
  for(int i=0;i<position-1;i++){
    current = current->next;
  }
  newNode->next = current->next;
  current->next = newNode; 
  return head;
  }
}
struct node * deleteVal(struct node *head,int position)
{
  if(position==0)
  {
    struct node *temp;
    temp = head;
    head = head-> next;
    free(temp);
    return head;
  }
  else{
    struct node *current=NULL,*prevNode=NULL;
    current = head;
    for(int i=0;i<position;i++)
    {
      prevNode = current;
      current = current ->next;
    }
    prevNode->next = current->next;
    free(current);
    return head;
  }
}
int searchVal(struct node* head,int item)
{
    int loc = -1;
    struct node *current = head;
    while(current!=NULL)
    {
      loc = loc + 1;
      if(item==current->data)
      {
        break;
      }
      current = current->next;
    }
    return loc;
}

int main()
{
    int n;
    scanf("%d",&n);
    struct node *head=NULL,*current=NULL;
    //creating Linked list with n elements
    for(int i=0;i<n;i++)
    {   
        struct node *newNode;
        newNode = (struct node*) malloc(sizeof(struct node));
        newNode->data = rand()%100;
        newNode->next = NULL;
        if(head==NULL)
        {
            head = newNode;
            current = head;
        }
        else{
            current -> next = newNode;
            current = newNode;
        }
    }
    //traversing and printing the linked list
    struct node * currentNode;
    currentNode = head;
    while(currentNode!=NULL)
    {
        printf("%d  ",currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
    //search an item within linked list
    int item,location;
    printf("Enter item to search: ");
    scanf("%d",&item);
    location= searchVal(head,item);
    //printing location or not found
    if(location<0)
    printf("Not found");
    else
    printf("Location: %d",location);

  
    //inserting a value at specific position
    int insertPos,element;
    printf("\nEnter position and value to insert: \n");
    scanf("%d%d",&insertPos,&element);
    head = insertVal(head,insertPos,element);
    struct node * cNode1;
    cNode1 = head;
           //printing updated linked list after inserting
    while(cNode1!=NULL){
      printf("%d ",cNode1->data);
      cNode1 = cNode1->next;
    }
    //deleting a value at specific position
    int deletePos;
    printf("\nEnter position to delete: \n");
    scanf("%d",&deletePos);
    head = deleteVal(head,deletePos);
    struct node *cNode2;
    cNode2 = head;
           //printing updated linked list after deletion
    while(cNode2!=NULL)
    {
      printf("%d ",cNode2->data);
      cNode2 = cNode2 -> next;
    }
    return 0;   
    }

