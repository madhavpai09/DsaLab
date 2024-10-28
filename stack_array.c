#include <stdio.h> 
#include <stdlib.h> 

struct Stack { 
    int top; 
    unsigned capacity; 
    int* array; 
}; 

struct Stack* createStack(unsigned capacity) 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 


int isFull(struct Stack* stack) 
{ 
    return stack->top == stack->capacity - 1; 
} 


int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1; 
} 

void push(struct Stack* stack, int item) 
{ 
    if (isFull(stack)) 
        return; 
    stack->array[++stack->top] = item; 
    printf("%d pushed to stack\n", item); 
} 

int pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) { 
        return 0;}
    else{
    return stack->array[stack->top--]; 
    }
} 


int peek(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return 0; 
    return stack->array[stack->top]; 
} 

int main() 
{ 
    struct Stack* stack = createStack(100); 
    int choice=0;
    int n;
    while(choice<=3)
    {
    printf("\nEnter: \n1.Push \n2.Pop \n3.Display\n\nEnter any negative number to exit.");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1: printf("Enter your value");
                scanf("%d",&n);
                push(stack,n);
                break;
        case 2: pop(stack);
                break;
        case 3: printf("%d",peek(stack));
                break;
        default:exit(0);
    }
    }
    return 0;
} 