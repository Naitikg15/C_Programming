#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top >= MAX - 1)
        printf("\nStack Overflow\n");
    else
        stack[++top] = item;
}

char pop() {
    if (top < 0)
        printf("\nStack Underflow\n");
    else
        return stack[top--];
}

int precedence(char symbol) {
    switch (symbol) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char item, x;
    push('(');  
    strcat(infix, ")");
    while (infix[i] != '\0') {
        item = infix[i];
        if (item == '(') {
            push(item);
        } else if (isalnum(item)) {
            postfix[j++] = item;
        } else if (item == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); 
        } else {
            while (precedence(stack[top]) >= precedence(item)) {
                postfix[j++] = pop();
            }
            push(item);
        }
        i++;
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    gets(infix);
    infixToPostfix(infix, postfix);
    printf("\nPostfix expression: %s\n", postfix);
    return 0;
}
