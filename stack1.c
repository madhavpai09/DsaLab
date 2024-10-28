#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* createNode(int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

typedef struct Stack {
    Node* head;
} Stack;

void initializeStack(Stack* stack) { stack->head = NULL; }

int isEmpty(Stack* stack) {
    return stack->head == NULL;
}

void push(Stack* stack, int new_data) {
    Node* new_node = createNode(new_data);
    if (!new_node) {
        printf("\nStack Overflow");
        return;
    }
    new_node->next = stack->head;
    stack->head = new_node;
}

void pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("\nStack Underflow\n");
        return;
    }
    else {
      
        Node* temp = stack->head;
        stack->head = stack->head->next;
    }
}

int peek(Stack* stack) {
    if (!isEmpty(stack)){
        printf("The element: %d",stack->head->data);
        return 0;}
    else{
        printf("\nStack is empty");
        return 0;
    }
}
int main()
{
    Stack stack;
    int choice=0,n;
    while(choice<=3)
    {
    printf("\nEnter: \n1.Push \n2.Pop \n3.Display\n\nEnter any negative number to exit.");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1: printf("Enter your value");
                scanf("%d",&n);
                push(&stack,n);
                break;
        case 2: pop(&stack);
                break;
        case 3: (peek(&stack));
                break;
        default:exit(0);
    }
    }
    return 0;
}
