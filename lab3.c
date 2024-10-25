#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}Node;
Node *First=NULL;
Node *Last1=NULL;
Node *Second=NULL;
Node *Last2=NULL;

Node* createNode()
{
    int item;
    Node *ptr=(Node*)malloc(sizeof(Node));
    printf("Enter the data to insert into the list");
    scanf("%d",&item);
    if(ptr!=NULL)
    {
        ptr->data=item;
        ptr->link=NULL;
    }
    printf("Address of newly create node=%p\n",ptr);
    return ptr;
}

void CreateList(Node **head,Node **tail)
{
       Node *temp=createNode();
    if(temp!=NULL && *head==NULL)
            *head=*tail=temp;
    else if(temp!=NULL && *head!=NULL)
    {
        (*tail)->link=temp;
        *tail=temp;
    }
    else
        printf("Insertion Not possible");
}

void display(Node *head)
{
    Node *temp=head;
    if(temp==NULL)
    {
        printf("\nList is Empty\n");
        return;
    }
    else
    {
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->link;
    }
    }

}
void sort(Node *head)
{
    int temp;
    Node *cur,*next;
    cur=head;
    if(cur==NULL)
    {
        printf("\nList is empty. Sort not possible\n");
        return;
    }
    while(cur!=NULL)
    {
        next=cur->link;
        while(next!=NULL)
        {
            if(cur->data >next->data)
            {
                temp=cur->data;
                cur->data=next->data;
                next->data=temp;
            }
            next=next->link;
        }
        cur=cur->link;
    }
}

void reverse(Node *head)
{
    Node *prev,*cur,*next;
    cur=head;
    prev=NULL;
    if(cur==NULL)
    {
        printf("\nList is empty. Sort not possible\n");
        return;
    }
    else if(cur->link==NULL)
    {
        printf("List consist of only one element. Hence List reverse is not allowed\n");
        return;
    }
    else
    {
        while(cur!=NULL)
       {
        next=cur->link;
        cur->link=prev;
        prev=cur;
        cur=next;
       }
      First=prev;
    }
}


void listConcatenation()
{
    if(Last1!=NULL && Second!=NULL)
    {
        Last1->link=Second;
    }
    else
    {
        printf("List concatenation not possible");
    }


}
int main()
{
    int choice=0;

    while(choice>=0 && choice<=8)
    {
        printf("\nEnter \n1.Create first list\n2.Create Second List\n3.Display First List\n4.Display Second List\n5.Sort\n6.reverse\n7.List Concatenation\n8.Exit\n");
    scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("address of First Pointer = %p\n",First);
                   CreateList(&First,&Last1);
                   break;
            case 2:CreateList(&Second,&Last2);
                   break;
            case 3:printf("\n List Elements are\n");
                display(First);
                break;
            case 4:printf("\n List Elements are\n");
                display(Second);
                break;
            case 5:printf("\n List Elements before Sort operation are\n");
                   display(First);
                   sort(First);
                   printf("\nList Elements after sorting are\n");
                   display(First);
                  break;
            case 6:printf("\nList Elements before reverse operation are\n");
                   display(First);
                   reverse(First);
                   printf("\nReversed List Elements are\n");
                   display(First);
                   break;
            case 7:printf("\nFirst List before concatenation are\n");
                   display(First);
                   listConcatenation();
                   printf("\n First List after concatenation\n");
                   display(First);
            case 8:printf("Exiting from execution.....\n");
                   exit(0);
        }
    }
    return 0;
}
