#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
    int stack_size;
    int top;
    char *stack;
} STACK;

void make_stack(STACK *stack)
{
    stack->stack = malloc(sizeof(char) * (stack->stack_size));
    return;
}
void push(STACK *stack, char value)
{
    if (stack->stack_size - 1 != stack->top)
    {
        stack->stack[++stack->top] = value;
    }
    return;
}
char pop(STACK *stack)
{
    if (stack->top == -1)
    {
        return 0;
    }
    else
    {
        return stack->stack[stack->top--];
    }
}
char top(STACK *stack)
{
    if (stack->top == -1)
    {
        return 0;
    }
    else
    {
        return stack->stack[stack->top];
    }
}
int empty(STACK *stack)
{
    if (stack->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    while (1)
    {
        char input[101] = {
            0,
        };
        scanf("%[^\n]", input);
        getchar();
        STACK stack;
        stack.top = -1;
        stack.stack_size = strlen(input) + 1;
        make_stack(&stack);
        if (!strcmp(input, "."))
        {
            break;
        }
        for (int i = 0; i < strlen(input); i++)
        {
            if (input[i] == '(' || input[i] == '[')
            {
                push(&stack, input[i]);
            }
            else if (input[i] == ']')
            {
                if (top(&stack) == '[' && !empty(&stack))
                {
                    pop(&stack);
                }
                else
                {
                    push(&stack, '0');
                }
            }
            else if (input[i] == ')')
            {
                if (top(&stack) == '(' && !empty(&stack))
                {
                    pop(&stack);
                }
                else
                {
                    push(&stack, '0');
                }
            }
        }
        if (empty(&stack))
            printf("yes\n");
        else
            printf("no\n");
        free(stack.stack);
    }
    return 0;
}