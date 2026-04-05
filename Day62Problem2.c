#include <stdlib.h>
#include <stdbool.h>

void dfs(int** rooms, int* roomsColSize, int room, bool* visited) {
    visited[room] = true;

    for (int i = 0; i < roomsColSize[room]; i++) {
        int key = rooms[room][i];
        if (!visited[key]) {
            dfs(rooms, roomsColSize, key, visited);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool* visited = (bool*)calloc(roomsSize, sizeof(bool));

    dfs(rooms, roomsColSize, 0, visited);

    // Check if all rooms are visited
    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) {
            free(visited);
            return false;
        }
    }

    free(visited);
    return true;
}
