#include <stdio.h>

void findPairs(int arr[], int n, int sum) {
    printf("Pairs with sum %d are:\n", sum);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == sum) {
                printf("(%d, %d)\n", arr[i], arr[j]);
            }
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 6;
    findPairs(arr, n, sum);
    return 0;
}
//
2.Write a program to reverse an array in place? In place means you cannot create a new array. You have to update the original array.
#include <stdio.h>

void reverseArray(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    while (start < end) {
        // Swap elements at start and end indices
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move start index forward and end index backward
        start++;
        end--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Reverse the array in place
    reverseArray(arr, n);

    printf("Reversed array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
3.Write a program to check if two strings are a rotation of each other?
  #include <stdio.h>
#include <string.h>

int areRotations(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Check if lengths of both strings are same
    if (len1 != len2)
        return 0;

    // Concatenate str1 with itself
    char temp[2 * len1 + 1];
    strcpy(temp, str1);
    strcat(temp, str1);

    // Check if str2 is a substring of temp
    if (strstr(temp, str2) != NULL)
        return 1;
    else
        return 0;
}

int main() {
    char str1[] = "abcd";
    char str2[] = "cdab";

    if (areRotations(str1, str2))
        printf("Yes, %s and %s are rotations of each other.\n", str1, str2);
    else
        printf("No, %s and %s are not rotations of each other.\n", str1, str2);

    return 0;
}
4. Write a program to print the first non-repeated character from a string?
  #include <stdio.h>
#include <string.h>

#define NO_OF_CHARS 256

char firstNonRepeatingChar(char *str) {
    int count[NO_OF_CHARS] = {0};
    int i;

    // Count frequency of each character
    for (i = 0; str[i]; i++)
        count[str[i]]++;

    // Find the first non-repeating character
    for (i = 0; str[i]; i++) {
        if (count[str[i]] == 1)
            return str[i];
    }

    // If no non-repeating character found, return null character
    return '\0';
}

int main() {
    char str[] = "aabbccdeeff";

    char result = firstNonRepeatingChar(str);

    if (result != '\0')
        printf("The first non-repeating character is: %c\n", result);
    else
        printf("No non-repeating character found.\n");

    return 0;
}
5.
#include <stdio.h>

// Function to move disk from source to destination
void moveDisk(int n, char source, char destination) {
    printf("Move disk %d from %c to %c\n", n, source, destination);
}

// Function to implement Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        moveDisk(n, source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);
    moveDisk(n, source, destination);
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int numDisks = 3;
    char source = 'A', auxiliary = 'B', destination = 'C';

    printf("Tower of Hanoi solution for %d disks:\n", numDisks);
    towerOfHanoi(numDisks, source, auxiliary, destination);

    return 0;
}
6. Read about infix, prefix, and postfix expressions. Write a program to convert postfix to prefix expression
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack implementation
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

void push(Stack *s, char c) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = c;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

char* postfixToPrefix(char *postfix) {
    Stack stack;
    initialize(&stack);

    int len = strlen(postfix);
    char *prefix = (char*)malloc((len + 1) * sizeof(char));
    int j = 0;

    // Scan postfix expression from left to right
    for (int i = 0; i < len; i++) {
        char c = postfix[i];

        // If current symbol is an operand, push it onto the stack
        if (isalnum(c)) {
            push(&stack, c);
        } else {
            // If current symbol is an operator, pop two operands from the stack
            char operand1 = pop(&stack);
            char operand2 = pop(&stack);

            // Combine them with the operator and push the resulting expression back onto the stack
            prefix[j++] = c;
            prefix[j++] = operand2;
            prefix[j++] = operand1;
            push(&stack, prefix[j-1]);
            prefix[j++] = '\0';
        }
    }

    // Final prefix expression is stored at the top of the stack
    char *finalPrefix = (char*)malloc((strlen(stack.items) + 1) * sizeof(char));
    strcpy(finalPrefix, stack.items);

    return finalPrefix;
}

int main() {
    char postfix[] = "ab+c*";
    printf("Postfix expression: %s\n", postfix);

    char *prefix = postfixToPrefix(postfix);
    printf("Prefix expression: %s\n", prefix);

    free(prefix);
    return 0;
}
7.. Write a program to convert prefix expression to infix expression
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Stack implementation
typedef struct {
    char items[100];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

void push(Stack *s, char c) {
    if (s->top == 99) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = c;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

// Function to check if character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert prefix expression to infix expression
char* prefixToInfix(char *prefix) {
    Stack stack;
    initialize(&stack);

    int len = strlen(prefix);
    char *infix = (char*)malloc((2 * len + 1) * sizeof(char));
    int j = 0;

    // Scan prefix expression from right to left
    for (int i = len - 1; i >= 0; i--) {
        char c = prefix[i];

        // If current symbol is an operand, push it onto the stack
        if (!isOperator(c)) {
            push(&stack, c);
        } else {
            // If current symbol is an operator, pop two operands from the stack
            char operand1 = pop(&stack);
            char operand2 = pop(&stack);

            // Construct the infix expression by combining the operands and operator
            infix[j++] = '(';
            infix[j++] = operand1;
            infix[j++] = c;
            infix[j++] = operand2;
            infix[j++] = ')';
            infix[j++] = '\0';

            // Push the resulting expression back onto the stack
            push(&stack, infix[j-2]);
        }
    }

    // Final infix expression is stored at the top of the stack
    char *finalInfix = (char*)malloc((strlen(stack.items) + 1) * sizeof(char));
    strcpy(finalInfix, stack.items);

    return finalInfix;
}

int main() {
    char prefix[] = "*+AB-CD";
    printf("Prefix expression: %s\n", prefix);

    char *infix = prefixToInfix(prefix);
    printf("Infix expression: %s\n", infix);

    free(infix);
    return 0;
}
8.Write a program to check if all the brackets are closed in a given code snippet
#include <stdio.h>
#include <stdlib.h>

// Stack implementation
typedef struct {
    char items[100];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

void push(Stack *s, char c) {
    if (s->top == 99) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = c;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

// Function to check if brackets are properly closed
int areBracketsClosed(char *code) {
    Stack stack;
    initialize(&stack);

    // Scan code snippet character by character
    for (int i = 0; code[i] != '\0'; i++) {
        char c = code[i];
        
        // If current character is an opening bracket, push it onto the stack
        if (c == '(' || c == '[' || c == '{') {
            push(&stack, c);
        } 
        // If current character is a closing bracket, pop from the stack and check for matching opening bracket
        else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty(&stack)) {
                // If stack is empty and encounter a closing bracket, brackets are not properly closed
                return 0;
            }

            char top = pop(&stack);

            // Check if the popped opening bracket matches the current closing bracket
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return 0;
            }
        }
    }

    // If stack is empty after scanning the entire code, all brackets are properly closed
    return isEmpty(&stack);
}

int main() {
    char code[] = "{ int a = (3 + 5) * 2; }";
    if (areBracketsClosed(code)) {
        printf("All brackets are properly closed.\n");
    } else {
        printf("Brackets are not properly closed.\n");
    }
    return 0;
}
9. Write a program to reverse a stack
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Stack implementation
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

int isFull(Stack *s) {
    return (s->top == MAX_SIZE - 1);
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

// Function to reverse a stack
void reverseStack(Stack *original, Stack *auxiliary) {
    while (!isEmpty(original)) {
        int temp = pop(original);
        push(auxiliary, temp);
    }
    // Copy contents of auxiliary stack back to original stack
    while (!isEmpty(auxiliary)) {
        int temp = pop(auxiliary);
        push(original, temp);
    }
}

// Function to print stack
void printStack(Stack *s) {
    printf("Stack: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main() {
    Stack original, auxiliary;
    initialize(&original);
    initialize(&auxiliary);

    // Push elements onto the stack
    push(&original, 1);
    push(&original, 2);
    push(&original, 3);
    push(&original, 4);

    printf("Original ");
    printStack(&original);

    // Reverse the stack
    reverseStack(&original, &auxiliary);

    printf("Reversed ");
    printStack(&original);

    return 0;
}
10.Write a program to find the smallest number using a stack
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Stack implementation
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

int isFull(Stack *s) {
    return (s->top == MAX_SIZE - 1);
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

// Function to find the smallest number in a stack
int findSmallestNumber(Stack *s) {
    int smallest = s->items[0];
    for (int i = 1; i <= s->top; i++) {
        if (s->items[i] < smallest) {
            smallest = s->items[i];
        }
    }
    return smallest;
}

int main() {
    Stack s;
    initialize(&s);

    // Push elements onto the stack
    push(&s, 5);
    push(&s, 3);
    push(&s, 9);
    push(&s, 1);

    printf("Stack: ");
    for (int i = 0; i <= s.top; i++) {
        printf("%d ", s.items[i]);
    }
    printf("\n");

    int smallest = findSmallestNumber(&s);
    printf("Smallest number in the stack: %d\n", smallest);

    return 0;
}
