#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure to hold operators
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function to create a stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Look at the top element without removing it
char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

// Remove and return the top element
char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

// Push a new element to the stack
void push(struct Stack* stack, char op) {
    stack->array[++stack->top] = op;
}

// Function to define operator precedence
int getPrecedence(char ch) {
    switch (ch) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
    return -1;
}

// Main logic of Shunting Yard Algorithm
void infixToPostfix(char* expression) {
    int i, k;
    struct Stack* stack = createStack(strlen(expression));
    if (!stack) return;

    for (i = 0, k = -1; expression[i]; ++i) {
        
        // 1. If it's an operand (A, B, 1, 2...), add to output
        if (isalnum(expression[i])) {
            expression[++k] = expression[i];
        }
        
        // 2. If it's '(', push it to stack
        else if (expression[i] == '(') {
            push(stack, expression[i]);
        }
        
        // 3. If it's ')', pop from stack until '(' is reached
        else if (expression[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                expression[++k] = pop(stack);
            pop(stack); // remove '(' from stack
        }
        
        // 4. If it's an operator
        else {
            while (!isEmpty(stack) && getPrecedence(expression[i]) <= getPrecedence(peek(stack)))
                expression[++k] = pop(stack);
            push(stack, expression[i]);
        }
    }

    // 5. Pop all remaining operators from the stack
    while (!isEmpty(stack))
        expression[++k] = pop(stack);

    expression[++k] = '\0';
    printf("Postfix Expression: %s\n", expression);
}

int main() {
    char exp[MAX];
    
    printf("Enter Infix Expression: ");
    scanf("%s", exp);
    
    infixToPostfix(exp);
    
    return 0;
}