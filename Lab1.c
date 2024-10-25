#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}NODE;
NODE* head=NULL;

NODE* createNode()
{
    int item;
    NODE *ptr=(NODE*)malloc(sizeof(NODE));
    printf("Enter a value\n");
    scanf("%d",&item);
    if(ptr==NULL)
        printf("Memory is not allocated\n");
    else
    {
        ptr->data=item;
        ptr->link=NULL;
    }
    return ptr;
}
void insert_beg()
{
    NODE *ptr=createNode();
    if(ptr!=NULL &&head!=NULL)
    {
        ptr->link=head;
        head=ptr;
    }
    else if(head==NULL)
        head=ptr;
    else
        printf("Insertion not possible\n");
}  
void insert_end()
{
    NODE *temp,*ptr;
    ptr=createNode();
    temp=head;
    if(ptr==NULL)
        printf("INsertion node possible...");
    else if(head==NULL)
        head=ptr;
    else
    {
        while(temp->link!=NULL)
          temp=temp->link;

        temp->link=ptr;
    }
}
void insert_pos()
{
    int loc,i;
    NODE *temp,*ptr;
    ptr=createNode();
    if(ptr==NULL)
        printf("Insertion not possible\n");
    else if(head==NULL)
       printf("Since list is empty, insertion at the given position is not allowed\n");
    else
    {
        printf("Enter the position\n");
        scanf("%d",&loc);
        temp=head;
        for(i=0;i<loc-1;i++)
        {
            temp=temp->link;
            if(temp==NULL)
            {
                printf("Insertion not possible. exceeds the number of elements");
                return;
            }
        }
        ptr->link=temp->link;
        temp->link=ptr;
    }
}
void display()
{
    NODE *temp=head;
    if(temp==NULL)
        printf("List is empty");
    else
    {
        printf("List elements are\n");
        while(temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->link;
        }
    }
}
int main()
{
    int choice=0;
   while(choice<=5)
   {
       printf("\nEnter 1.Insert node at Beginning\n 2.Insert node at end of the list.\n 3.Insert at given position 4.Display list elements\n 5.Exit from execution\n");
       scanf("\n%d",&choice);
       switch(choice)
       {
           case 1:insert_beg();
                  break;
           case 2:insert_end();
                  break;
           case 3:insert_pos();
                  break;
           case 4:display();
                  break;
          case 5:printf("Exiting from Execution\n");
                exit(0);
          default:
                 exit(0);
        }
   }


}
