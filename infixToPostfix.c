#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100

typedef struct
{
    int top;
    char array[MAX_SIZE];
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

char peek(Stack *stack)
{
    return stack->array[stack->top];
}

void push(Stack *stack, char item)
{
    stack->array[++stack->top] = item;
}

char pop(Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '\0';
}

int precedence(char op);
void infixToPostfix(char *infix, char *postfix)
{
    Stack *stack = createStack();
    int i, k;
    for (i = 0, k = -1; infix[i]; ++i)
    {
        char ch = infix[i];
        if (isalnum(ch))
            postfix[++k] = ch;
        else if (ch == '(')
            push(stack, ch);
        else if (ch == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                postfix[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return; // Invalid expression
            else
                pop(stack); // Discard '('
        }
        else
        { // Operator
            while (!isEmpty(stack) && peek(stack) != '(' && precedence(ch) <= precedence(peek(stack)))
                postfix[++k] = pop(stack);
            push(stack, ch);
        }
    }
    while (!isEmpty(stack))
        postfix[++k] = pop(stack);
    postfix[++k] = '\0';
}
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int main()
{
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    clrscr();
    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strcspn(infix, "\n")] = '\0';
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    getch();
    return 0;
}

