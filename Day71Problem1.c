#include <stdio.h>
#include <string.h>

#define EMPTY -1

int table[100];

// Hash function
int hash(int key, int m) {
    return key % m;
}

// Insert using quadratic probing
void insert(int key, int m) {
    int h = hash(key, m);
    
    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;
        
        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
    }
}

// Search using quadratic probing
int search(int key, int m) {
    int h = hash(key, m);
    
    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;
        
        if (table[index] == EMPTY)
            return 0; // not found
        
        if (table[index] == key)
            return 1; // found
    }
    
    return 0;
}

int main() {
    int m, q;
    scanf("%d", &m);   // table size
    scanf("%d", &q);   // number of operations

    // Initialize table
    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    while (q--) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        }
        else if (strcmp(op, "SEARCH") == 0) {
            if (search(key, m))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}
