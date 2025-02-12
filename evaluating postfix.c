#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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

void push(Stack *stack, int item)
{
    stack->array[++stack->top] = item;
}

int pop(Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return -1;
}

int evaluatePostfix(char *expression)
{
    Stack *stack = createStack();
    int i, operand1, operand2;
    for (i = 0; expression[i]; ++i)
    {
        char ch = expression[i];
        if (isdigit(ch))
            push(stack, ch - '0');
        else
        {
            operand2 = pop(stack);
            operand1 = pop(stack);
            switch (ch)
            {
            case '+':
                push(stack, operand1 + operand2);
                break;
            case '-':
                push(stack, operand1 - operand2);
                break;
            case '*':
                push(stack, operand1 * operand2);
                break;
            case '/':
                push(stack, operand1 / operand2);
                break;
            }
        }
    }
    return pop(stack);
}

int main()
{
    int result;
    char expression[MAX_SIZE];
    clrscr();
    printf("Enter a valid postfix expression: ");
    fgets(expression, MAX_SIZE, stdin);
    expression[strcspn(expression, "\n")] = '\0';

    result = evaluatePostfix(expression);
    printf("Result: %d\n", result);
    getch();
    return 0;
}