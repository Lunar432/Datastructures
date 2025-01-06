#define MAX 15
#include <stdio.h>
#include <stdlib.h>

int* push(int stack[], int *top, int value) {
    if (*top == (MAX - 1)) {
        printf("Overflow. Stack is full.\n");
        return stack;
    }
    *top = *top + 1;
    stack[*top] = value;
    return stack;
}

int* pop(int stack[], int *top) {
    if (*top < 0) {
        printf("Underflow. Stack is empty.\n");
        return stack;
    }
    int item = stack[*top];
    printf("Popped item: %d\n", item);
    *top = *top - 1;
    return stack;
}

int main() {
    int stack[MAX];
    int top = -1;
    int pushItem;
    int a = 0;
    int *newstack1 = NULL;

    while (a != 3) {
        printf("\nChoose your option --> (1-3)\n");
        printf("1. Push an item onto stack\n");
        printf("2. Pop an item off of stack\n");
        printf("3. Exit\n");
        scanf("%d", &a);

        switch (a) {
            case 1:
                printf("Enter item to push: \n");
                scanf("%d", &pushItem);
                newstack1 = push(stack, &top, pushItem);
                if (top == -1) {
                    printf("Empty stack.\n");
                } else {
                    printf("Updated Stack is: \n");
                    for (int i = 0; i <= top; i++) {
                        printf("%d  ", newstack1[i]);
                    }
                    printf("\n");
                }
                break;

            case 2:
                pop(stack, &top);
                if (top == -1) {
                    printf("Empty stack.\n");
                } else {
                    printf("Updated Stack is: \n");
                    for (int i = 0; i <= top; i++) {
                        printf("%d  ", stack[i]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                printf("System exiting...\n");
                break;

            default:
                printf("Invalid Input.\n");
        }
    }
    return 0;
}
