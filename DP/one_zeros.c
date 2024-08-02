#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Counts{
    int count0;
    int count1;
};

struct Counts *countZeroOnes(char str[]){
    int n = strlen(str);
    struct Counts *counts = malloc(sizeof(struct Counts));
    counts->count0 = 0;
    counts->count1 = 0;

    for(int i = 0; i < n; i++){
        if(str[i] == '0'){
            counts->count0 += 1;
        } else if (str[i] == '1') {
            counts->count1 += 1;
        }
    }

    return counts;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

int call(char *strs[], int m, int n, int k, int idx, int ***dp){

    if(idx == k){
        return 0;
    }

    if(dp[idx][m][n] != -1){
        printf("memo hit for idx %d m %d n %d", idx, m, n);
        return dp[idx][m][n];
    }

    // exclude
    int exclude = call(strs, m, n, k, idx + 1, dp);

    // include
    struct Counts *counts = countZeroOnes(strs[idx]);

    int include = 0;

    if(counts->count0 <= m && counts->count1 <= n){
        include = 1 + call(strs, m - counts->count0, n - counts->count1, k, idx + 1, dp);
    }

    free(counts);

    dp[idx][m][n] = max(exclude, include);

    return dp[idx][m][n]; 

}


void free3DArray(int ***array, int k, int m) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            free(array[i][j]);
        }
        free(array[i]);
    }
    free(array);
}

int largestSubsetCount(char *strs[], int m, int n, int k){
    int ***dp = malloc(k * sizeof(int **));
    for (int i = 0; i < k; i++) {
        dp[i] = malloc((m + 1) * sizeof(int *));
        for (int j = 0; j <= m; j++) {
            dp[i][j] = malloc((n+1) * sizeof(int));
            for(int l = 0; l <= n; l++){
                dp[i][j][l] = -1;
            }
        }
    }

    int count = call(strs, m, n, k, 0, dp);

    // for (int i = 0; i < k; i++) {
    //     printf("Layer %d:\n", i);
    //     for (int j = 0; j < m; j++) {
    //         for (int l = 0; l < n; l++) {
    //             printf("%d ", dp[i][j][l]);
    //         }
    //         printf("\n");
    //     }
    //     printf("\n");
    // }

    free3DArray(dp, k, m);

    return count;
}

int main(){
    int k, m, n;

    printf("Enter the number of strings: ");
    scanf("%d", &k);

    // Allocate memory for the strings
    char **strs = malloc(k * sizeof(char *));
    for (int i = 0; i < k; i++) {
        strs[i] = malloc(100 * sizeof(char)); // Allocate space for each string
    }

    printf("Enter the strings:\n");
    for (int i = 0; i < k; i++) {
        scanf("%s", strs[i]);
    }

    printf("Enter the maximum number of 0s (m): ");
    scanf("%d", &m);

    printf("Enter the maximum number of 1s (n): ");
    scanf("%d", &n);

    printf("Largest subset count: %d\n", largestSubsetCount(strs, m, n, k));

    // Free allocated memory for strings
    for (int i = 0; i < k; i++) {
        free(strs[i]);
    }
    free(strs);

    return 0;
}