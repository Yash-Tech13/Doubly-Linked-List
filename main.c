#include <stdio.h>
#include <stdlib.h>

struct abc
{
  int data;
  struct abc *prev, *next;
};

void create(int n, struct abc* head)
{
  struct abc *temp;
  for(int i=0;i<n;i++)
  {
    temp = (struct abc*)malloc(sizeof(struct abc));
    printf("Enter data: ");
    scanf("%d",&temp->data);
    head->next = temp;
    temp->next = NULL;
    temp->prev = head;
    head = head->next;
  }
}

void display(struct abc *head)
{
  printf("Elements of the list are: \n");
  while(head!=NULL)
  {
    printf("%d ",head->data);
    head = head->next;
  }
  printf("\n");
}

void insertMiddle(int e, struct abc *head)
{
  struct abc *temp, *p, *q;
  q = head;
  temp = (struct abc*)malloc(sizeof(struct abc));
  printf("Enter data: ");
  scanf("%d",&temp->data);
  temp->next = NULL;
  temp->prev = NULL;

  while(e != head->data)
  {
    head = head->next;
  }
  p = head->next;

  p->prev = temp;
  temp->next = p;

  head->next = temp;
  temp->prev = head;

  display(q);
}

void insertEnd(struct abc *head)
{
  struct abc *temp;
  temp = (struct abc*)malloc(sizeof(struct abc));
  printf("Enter data: ");
  scanf("%d",&temp->data);
  temp->next = NULL;
  temp->prev = NULL;

  while(head->next != NULL)
  {
    head = head->next;
  }
  temp->prev = head;
  head->next = temp;
}

struct abc* insertStart(struct abc *head)
{
  struct abc *temp;
  temp = (struct abc*)malloc(sizeof(struct abc));
  printf("Enter data: ");
  scanf("%d",&temp->data);
  temp->prev = NULL;

  temp->next = head;
  head->prev = temp;

  return temp;
}

struct abc* deleteHead(struct abc *head)
{
  struct abc *p;
  p = head;
  head = head->next;
  head->prev = NULL;
  free(p);
  return head;
}

void delete(struct abc *head, int data)
{
  while(head->data != data)
  {
    head = head->next;
  }
  struct abc *p, *q;
  p = head->prev;
  q = head->next;

  p->next = q;
  q->prev = p;

  free(head); 
}

void deleteLast(struct abc *head)
{
  struct abc *p;
  while(head->next != NULL)
  {
    head = head->next;
  }
  p = head->prev;
  p->next = NULL;
  free(head);
}

void displayReverse(struct abc *head)
{
  while(head->next != NULL)
  {
    head = head->next;
  }

  while(head!=NULL)
  {
    printf("%d\n",head->data);
    head = head->prev;
  }
}

int main(void) 
{
  struct abc *head;
  head = (struct abc*)malloc(sizeof(struct abc));
  int choice,n,e;
  
  do
  {
    printf("\nMenu\n");
    printf("1. Create list\n");
    printf("2. Insert at start\n");
    printf("3. Insert in middle\n");
    printf("4. Insert at end\n");
    printf("5. Delete head\n");
    printf("6. Delete middle node\n");
    printf("7. Delete last node\n");
    printf("8. Display list forward\n");
    printf("9. Display backward\n");
    printf("10. Exit\n");
    printf("Enter choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1:
      printf("Enter data for head node\n");
      scanf("%d",&head->data);
      head->next = NULL;
      head->prev = NULL;
      printf("Enter number of nodes\n");
      scanf("%d",&n);
      create(n,head);
      break;

      case 2:
      head = insertStart(head);
      display(head);
      break;

      case 3:
      printf("Enter element after which you want to insert: ");
      scanf("%d",&e);
      insertMiddle(e, head);
      break;

      case 4:
      insertEnd(head);
      display(head);
      break;

      case 5:
      head = deleteHead(head);
      display(head);
      break;

      case 6:
      printf("Enter node which you want to delete: ");
      scanf("%d",&e);
      delete(head,e);
      display(head);
      break;

      case 7:
      deleteLast(head);
      display(head);
      break;

      case 8:
      display(head);
      break;

      case 9:
      displayReverse(head);
      break;

      case 10:
      printf("Good Bye!!!");
      break;

      default:
      printf("Enter valid number.\n");
    }
  }while(choice != 10);
  return 0;
}
