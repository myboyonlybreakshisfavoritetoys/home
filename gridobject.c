#include <stdio.h>

void sinkObject(int N, int M, int grid[N][M], int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M || grid[r][c] == 0) {
        return;
    }

    grid[r][c] = 0;

    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dr != 0 || dc != 0) {
                sinkObject(N, M, grid, r + dr, c + dc);
            }
        }
    }
}

int main() {
    int N, M;

    printf("Enter N and M (rows and columns): ");
    if (scanf("%d %d", &N, &M) != 2) {
        printf("Invalid input for N and M.\n");
        return 1;
    }

    int grid[N][M];

    printf("Enter the %d x %d grid (0s and 1s):\n", N, M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (scanf("%d", &grid[i][j]) != 1) {
                printf("Error reading grid at row %d, col %d.\n", i, j);
                return 1;
            }
        }
    }

    int objectCount = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 1) {
                objectCount++;
                sinkObject(N, M, grid, i, j);
            }
        }
    }

    printf("\nTotal number of objects: %d\n", objectCount);

    return 0;
}
