
#include <stdio.h>
#include<stdlib.h>

#define MAX_INT 1000;

int min(int x, int y){
    if(x < y){
        return x;
    } else {
        return y;
    }
}

int call(int n, int m, int **grid, int i, int j, int dp[n][m]){
    int end_i = n - 1;
    int end_j = m - 1;

    if(i == end_i && j == end_j) return grid[end_i][end_j];

    if(i > end_i || j > end_j) return MAX_INT;

    if(dp[i][j] != -1) return dp[i][j];

    int down = grid[i][j] + call(n, m, grid, i + 1, j, dp);
    int right = grid[i][j] + call(n, m, grid, i, j + 1, dp);

    dp[i][j] = min(down, right);

    return dp[i][j];
}

int findMinPathSum(int n, int m, int **grid)
{
    int dp[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dp[i][j] = -1;
        }
    }

    return call(n, m, grid, 0, 0, dp);
}

// [1,3,1],[1,5,1],[4,2,1]]
// 7

//  [[1,2,3],[4,5,6]]
// 12
int main() {
    int n, m;

    printf("Enter the number of rows (n): ");
    scanf("%d", &n);
    printf("Enter the number of columns (m): ");
    scanf("%d", &m);

    int **grid = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        grid[i] = malloc(m * sizeof(int));
    }

    printf("Enter the grid values:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    printf("Minimum path sum: %d\n", findMinPathSum(n, m, grid));

    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}