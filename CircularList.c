#include <stdio.h>
#include <stdlib.h>

typedef struct CircularList
{
    int data;
    struct CircularList *link;
}CNode;

CNode *first=NULL,*Last=NULL;
CNode *createNode()
{
    int item;
    CNode * ptr=(CNode*)malloc(sizeof(CNode));
    if(ptr!=NULL)
    {
        printf("\nEnter the value\n");
        scanf("%d",&item);
        ptr->data=item;
        ptr->link=NULL;
    }
    else
    {
        printf("\nMemory Overload\n");
        return 0;
    }
    return ptr;
}
void insertEnd()
{
    CNode *temp=createNode();
     if(temp!=NULL && first==NULL)
    {
        first=Last=temp;
        first->link=temp;
    }
    else if(temp!=NULL &&Last->link==first)
    {
        Last->link=temp;
        temp->link=first;
        Last=temp;
    }
    else
    {
        printf("\nNode Insertion is unsuccessful\n");
    }
}
void insertBeg()
{
    CNode *temp=createNode();
    if(temp!=NULL && first==NULL)
    {
        first=Last=temp;
        first->link=temp;
    }
    else
    {
        temp->link=first;
        first=temp;
        Last->link=first;
    }
}

/*void display()
{
    CNode *temp=first;
    if(temp==NULL)
        printf("\n List is empty\n");
    else
    {
      while(temp!=)
      {
          printf("%d\t",temp->data);
          temp=temp->link;
      }
    }
}*/
void del_beg()
{

    if(first==NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    if(first==Last)
        first=Last=NULL;
    else
    {
        printf("\nItem %d deleted successfully\n",first->data);
        first=first->link;
        Last->link=first;
    }
}
void del_end()
{
    if(first==NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    if(first==Last)
    {
        printf("\nItem %d is deleted successfully\n",first->data);
        first=Last=NULL;
    }
    else
    {
        CNode *temp=first;
        while(temp->link!=Last)
            temp=temp->link;
        printf("\nitem %d is deleted successfully\n",Last->data);
        temp->link=Last->link;
        Last=temp;
    }
}
void traverse()
{
    CNode *temp=first;
    if(temp==NULL)
    {
        printf("\n List is empty\n");
        return;
    }
    else
    {
         do
         {
             printf("%d\t",temp->data);
             temp=temp->link;
         }while(temp!=first);
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("Enter \n1.Insertion at Beginning\n2.Insertion at end\n3.Deletion at beginning\n4.Deletion at End\n5.traverse\nPress any Negative Number to exit from execution\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insertBeg();
                   break;
            case 2:insertEnd();
                   break;
            case 3:del_beg();
                   break;
            case 4:del_end();
                   break;
            case 5:printf("List Elements are\n");
                   traverse();
                   break;
            default:exit(0);
        }
    }
    return 0;
}