#include <stdio.h>

void objecter(int n, int m, int grid[n][m], int row, int col) {
    if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0) {
        return;
    }

    grid[row][col] = 0;

    for (int rowcheck = -1; rowcheck <= 1; rowcheck++) {
        for (int colcheck = -1; colcheck <= 1; colcheck++) {
            if (rowcheck != 0 || colcheck != 0) {
                objecter(n, m, grid, row + rowcheck, col + colcheck);
            }
        }
    }
}

int main() {
    int n, m, i ,j;


    scanf("%d %d", &n, &m);
   

    int grid[n][m];

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            scanf("%d", &grid[i][j]);

    }

    int count = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                count++;
                objecter(n, m, grid, i, j);
            }
        }
    }

    printf("%d", count);

    return 0;
}
