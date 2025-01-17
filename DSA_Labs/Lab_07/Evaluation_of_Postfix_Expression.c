#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int item) {
    if (top >= MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = item;
}

int pop() {
    if (top < 0)
        printf("Stack Underflow\n");
    else
        return stack[top--];
}

int evaluatePostfix(char postfix[]) {
    int i = 0, op1, op2;
    char item;
    while (postfix[i] != '\0') {
        item = postfix[i];
        if (isdigit(item)) {
            push(item - '0');
        } else {
            op2 = pop();
            op1 = pop();
            switch (item) {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    push(op1 / op2);
                    break;
            }
        }
        i++;
    }
    return pop();
}

int main() {
    char postfix[MAX];
    printf("Enter postfix expression: ");
    gets(postfix);
    printf("\nEvaluation result: %d\n", evaluatePostfix(postfix));
    return 0;
}
