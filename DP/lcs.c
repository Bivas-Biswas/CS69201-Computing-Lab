#include <stdio.h>
#include <string.h>

// Utility function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Returns length of LCS for X[0..m-1], Y[0..n-1]
int lcs(char* X, char* Y, int m, int n, int dp[][1000])
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);

    if (dp[m][n] != -1) {
        return dp[m][n];
    }
    return dp[m][n] = max(lcs(X, Y, m, n - 1, dp), lcs(X, Y, m - 1, n, dp));
}

// Driver code
int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);
    int dp[1000][1000];
    
    // Initialize dp array with -1
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = -1;
        }
    }

    printf("Length of LCS is %d\n", lcs(X, Y, m, n, dp));

    return 0;
}
