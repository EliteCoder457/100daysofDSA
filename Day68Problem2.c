#include <stdio.h>
#include <string.h>

#define MAX 26

// Queue
int queue[MAX], front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

// Function to find alien dictionary order
void alienOrder(char words[][100], int n) {
    int adj[MAX][MAX] = {0};   // adjacency matrix
    int indegree[MAX] = {0};
    int present[MAX] = {0};    // track used characters

    // Mark all characters present
    for (int i = 0; i < n; i++) {
        for (int j = 0; words[i][j]; j++) {
            present[words[i][j] - 'a'] = 1;
        }
    }

    // Build graph
    for (int i = 0; i < n - 1; i++) {
        char *w1 = words[i];
        char *w2 = words[i + 1];

        int len1 = strlen(w1);
        int len2 = strlen(w2);

        int found = 0;

        for (int j = 0; j < len1 && j < len2; j++) {
            if (w1[j] != w2[j]) {
                if (!adj[w1[j]-'a'][w2[j]-'a']) {
                    adj[w1[j]-'a'][w2[j]-'a'] = 1;
                    indegree[w2[j]-'a']++;
                }
                found = 1;
                break;
            }
        }

        // Invalid case
        if (!found && len1 > len2) {
            printf("");
            return;
        }
    }

    // Add nodes with indegree 0
    for (int i = 0; i < MAX; i++) {
        if (present[i] && indegree[i] == 0) {
            enqueue(i);
        }
    }

    char result[MAX];
    int index = 0;

    // Kahn's Algorithm
    while (!isEmpty()) {
        int curr = dequeue();
        result[index++] = curr + 'a';

        for (int i = 0; i < MAX; i++) {
            if (adj[curr][i]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    // Count unique characters
    int total = 0;
    for (int i = 0; i < MAX; i++) {
        if (present[i]) total++;
    }

    // Cycle check
    if (index != total) {
        printf("");
        return;
    }

    result[index] = '\0';
    printf("%s", result);
}

// Driver
int main() {
    char words[][100] = {"baa", "abcd", "abca", "cab", "cad"};
    int n = 5;

    alienOrder(words, n);

    return 0;
}
