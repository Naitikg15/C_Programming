#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top >= MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = item;
}

char pop() {
    if (top < 0)
        printf("Stack Underflow\n");
    else
        return stack[top--];
}

int isBalanced(char expr[]) {
    int i = 0;
    char item;
    while (expr[i] != '\0') {
        item = expr[i];
        if (item == '(' || item == '{' || item == '[') {
            push(item);
        } else if (item == ')' || item == '}' || item == ']') {
            if (top == -1)
                return 0;
            else {
                char temp = pop();
                if ((item == ')' && temp != '(') ||
                    (item == '}' && temp != '{') ||
                    (item == ']' && temp != '['))
                    return 0;
            }
        }
        i++;
    }
    return (top == -1) ? 1 : 0;
}

int main() {
    char expr[MAX];
    printf("Enter an expression: ");
    gets(expr);
    if (isBalanced(expr))
        printf("\nBalanced\n");
    else
        printf("\nNot Balanced\n");
    return 0;
}
