#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX_SIZE 100

typedef struct
{
    int top;
    int array[MAX_SIZE];
} Stack;

Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

int isFull(Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int item)
{
    if (isFull(stack))
    {
        printf("Stack overflow, cannot push \n");
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack undeflow. cannot pop \n");
        return -1;
    }
    return stack->array[stack->top--];
}

int display(Stack *stack)
{
    int i;
    if (isEmpty(stack))
    {
        printf("Stack is empty \n");
        return -1;
    }
    for (i = 0; i <= stack->top; i++)
    {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
    return 0;
}

int main()
{
    int choice, item;
    Stack *stack = createStack();
    clrscr();
    do
    {
        printf("\nStack operations \n");
        printf("1. Push\n");
        printf("2. PoP\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &item);
            push(stack, item);
            break;
        case 2:
            item = pop(stack);
            if (item != -1)
            {
                printf("Popped element %d\n", item);
            }
            break;
        case 3:
            display(stack);
            break;
        case 4:
            printf("Exiting...x.x.x.x");
            break;
        default:
            printf("Invalid choice");
        }
    } while (choice != 4);
    getch();
    return 0;
}