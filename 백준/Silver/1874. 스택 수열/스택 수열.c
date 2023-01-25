#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int stack_size;
    int top;
    int *stack;
} STACK;

void make_stack(STACK *stack)
{
    stack->top = -1;
    stack->stack = malloc(sizeof(int) * (stack->stack_size));
    return;
}
void push(STACK *stack, int value)
{
    if (stack->stack_size - 1 != stack->top)
    {
        stack->stack[++stack->top] = value;
        // stack->top += 1;
    }
    return;
}
int pop(STACK *stack)
{
    {
        return stack->stack[stack->top--];
    }
}
int top(STACK *stack)
{
    {
        return stack->stack[stack->top];
    }
}
int main()
{
    int n, num = 1, index = 0;
    scanf("%d", &n);
    char *result = (char *)calloc(n * 2 + 1, sizeof(char));
    int *arr = (int *)calloc(n, sizeof(int));
    STACK stack;
    stack.stack_size = n;
    make_stack(&stack);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 2 * n; i++)
    {
        if (i == 0 || top(&stack) < arr[index])
        {
            push(&stack, num++);
            result[i] = '+';
        }
        else if (top(&stack) == arr[index])
        {
            pop(&stack);
            result[i] = '-';
            index += 1;
        }
        else
        {
            printf("NO\n");
            free(stack.stack);
            free(result);
            return 0;
        }
    }
    for (int i = 0; i < 2 * n; i++)
    {
        printf("%c\n", result[i]);
    }
    free(stack.stack);
    free(result);
    return 0;
}