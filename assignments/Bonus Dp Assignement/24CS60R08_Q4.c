#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

int solve(int nums[], int i, int j, int n)
{
    int ans = 0;
    for (int k = i; k <= j; k++)
    {
        // Eat the kth apple after eating (i, k - 1) and (k + 1,
        // j) apples
        int temp = nums[k];
        if (j + 1 < n) // As apple j + 1 will become adjacent to k
                       // after eating k + 1 to j apples
            temp *= nums[j + 1];
        if (i - 1 >= 0) // As apple i- 1 will become adjacent to k
                        // after eating i to k - 1 apples
            temp *= nums[i - 1];
        // Recursively solve the left and right subproblems
        // and add their contribution
        temp += (solve(nums, i, k - 1, n) + solve(nums, k + 1, j, n));
        // If this choice of k yields a better answer
        ans = max(ans, temp);
    }
    return ans;
}

int main(){
    int n;
    printf("Enter the number of apples: ");
    scanf("%d", &n);

    int *nums = malloc(sizeof(int));

    printf("Enter the number of each apple: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }
    
    printf("The maximum points Hari can get by eating the apples wisely is : %d \n", solve(nums, 0, n - 1, n));
}