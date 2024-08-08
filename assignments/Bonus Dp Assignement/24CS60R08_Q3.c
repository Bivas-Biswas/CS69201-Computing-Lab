#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int count1(int n, int k, int x)
{
    if (n == 1)
    {
        if (x == 1)
            return 1;
        else
            return 0;
    }

    // printf("%d --> %d \n", n, x);

    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += count1(n - 1, k, i);
    }
    ans -= count1(n - 1, k, x);

    return ans;
}

int count2(int n, int k, int x, int **dp)
{
    if (n == 1)
    {
        if (x == 1)
            return 1;
        else
            return 0;
    }

    if (dp[n][x] != -1)
        return dp[n][x];
    // printf("%d --> %d \n", n, x);

    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += count2(n - 1, k, i, dp);
    }
    ans -= count2(n - 1, k, x, dp);

    dp[n][x] = ans;

    return dp[n][x];
}

void count3(int n, int k, int x, int *A, int *B)
{

       if (x == 1) {
        A[0] = 1;
        B[0] = 0;
    } else {
        A[0] = 0;
        B[0] = 1;
    }
     
    for (int i = 1; i < n; i++)
    {
        A[i] = B[i - 1];
        B[i] = B[i - 1] * (k - 2) + A[i - 1] * (k - 1);
    }
}

int main()
{
    int n = 4, k = 3, x = 2;

    // approach 1

    printf("Approach 1: Recursion -- %d \n", count1(n, k, x));

    /// approach 2
    int **dp = malloc((n + 1) * sizeof(int *));

    for (int i = 0; i <= n; i++)
    {
        dp[i] = malloc((k + 1) * sizeof(int));
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = -1;
        }
    }

    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= k; j++)
    //     {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("Approach 2: Using 2d DP -- %d \n", count2(n, k, x, dp));

    for (int i = 0; i <= n; i++)
    {
        free(dp[i]);
    }
    free(dp);

    // aproach 3
    int *A = malloc((n) * sizeof(int));
    int *B = malloc((n) * sizeof(int));

    count3(n, k, x, A, B);
    printf("Approach 3: Using 1d DP -- %d \n", A[n - 1]);
    free(A);
    free(B);
}