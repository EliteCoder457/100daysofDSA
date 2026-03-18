#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);
    // The stack will never need to be larger than the string itself
    char stack[len];
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];

        // Push opening brackets onto the stack
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } 
        else {
            // If we hit a closing bracket but the stack is empty, it's invalid
            if (top == -1) return false;

            char topChar = stack[top--];

            // Check for mismatch
            if (c == ')' && topChar != '(') return false;
            if (c == '}' && topChar != '{') return false;
            if (c == ']' && topChar != '[') return false;
        }
    }

    // If the stack is empty, all brackets were matched correctly
    return top == -1;
}
