#include <stdio.h>
#include <ctype.h>

int calculate(char* s) {
    long result = 0;
    long last = 0;
    long num = 0;
    char op = '+';  // previous operator

    for (int i = 0; s[i] != '\0'; i++) {

        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        // If operator OR end of string
        if ((!isdigit(s[i]) && s[i] != ' ') || s[i+1] == '\0') {

            if (op == '+') {
                result += last;
                last = num;
            }
            else if (op == '-') {
                result += last;
                last = -num;
            }
            else if (op == '*') {
                last = last * num;
            }
            else if (op == '/') {
                last = last / num; // truncates toward zero
            }

            op = s[i];
            num = 0;
        }
    }

    return result + last;
}
