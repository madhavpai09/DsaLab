#include <stdio.h>
#include <stdlib.h>

typedef struct term
{
    int coeff;
    int exp;
    struct term *next;
}TERM;

TERM *poly1=NULL,*poly2=NULL,*res_poly=NULL;
TERM *tail1=NULL,*tail2=NULL,*tail3=NULL;

TERM *createNOde(int c,int e)
{
    TERM *ptr=(TERM*)malloc(sizeof(TERM));
    if(ptr!=NULL)
    {
        ptr->coeff=c;
        ptr->exp=e;
        ptr->next=NULL;
    }
    return ptr;
}

void insert_term(int c,int e,TERM **poly)
{
    TERM *newNode=createNOde(c,e);
    if (*poly == NULL)
    {
        *poly = newNode;
    }
    else
    {
        TERM* temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayPolynomial(TERM *poly)
{

    if(poly==NULL)
    {
        printf("\nPolynomial does not consist of any terms.\n");
    }
    else
    {
        while(poly!=NULL)
        {
            printf("%dx^%d",poly->coeff,poly->exp);
            poly=poly->next;
            if(poly!=NULL)
                printf("+");
        }
    }
}

void addPolynomials(TERM *p1,TERM *p2)
{
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->exp > p2->exp)
        {
            insert_term(p1->coeff,p1->exp,&res_poly);
            p1=p1->next;
        }
        else if(p1->exp < p2->exp)
        {
            insert_term(p2->coeff,p2->exp,&res_poly);
            p2=p2->next;
        }
        else
        {
            int c_sum=p1->coeff+p2->coeff;
            if(c_sum!=0)
              insert_term(c_sum,p1->exp,&res_poly);
            p1=p1->next;
            p2=p2->next;
        }
    }
    while(p1!=NULL)
    {
        insert_term(p1->coeff,p1->exp,&res_poly);
        p1=p1->next;
    }
    while(p2!=NULL)
    {
        insert_term(p2->coeff,p2->exp,&res_poly);
        p2=p2->next;
    }
}

void readPolynomial(TERM **poly)
{
    int n,c,e;
    printf("\nEnter number of terms in the polynomial equation\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("\nEnter coefficient and exponent of term %d\n",i);
        scanf("%d%d",&c,&e);
        insert_term(c,e,poly);
    }
}
int main()
{
    printf("Enter the first polynomial:\n");
    readPolynomial(&poly1);

    printf("Enter the second polynomial:\n");
    readPolynomial(&poly2);

    printf("\nFirst Polynomial: ");
    displayPolynomial(poly1);

    printf("\nSecond Polynomial: ");
    displayPolynomial(poly2);

    addPolynomials(poly1, poly2);
    printf("\nSum of Polynomials: ");
    displayPolynomial(res_poly);
}
