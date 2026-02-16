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

    if (scanf("%d %d", &N, &M) != 2) return 1;

    int grid[N][M];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &grid[i][j]);
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

    printf("%d\n", objectCount);

    return 0;
}
