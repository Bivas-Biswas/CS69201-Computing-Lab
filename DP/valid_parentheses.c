#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

int call(char s[], int n, int *dp){

    int ans = 0;
    for(int i = 1; i < n; i++){
        int c = s[i];
        int j = i - dp[i] - 1;
        
        if(c == ')' && s[j] == '('){
            dp[i+1] = dp[i] + dp[j] + 2;
            ans = max(ans, dp[i+1]);
        }

    }

    return ans;

}

int countValidParentheses(char s[], int n){
    int *dp = malloc((n+1) * sizeof(int));

    for(int i = 0; i <= n; i++){
        dp[i] = 0;
    }

    return call(s, n, dp);

}



int main() {
    char s[100];
    int n;

    printf("Enter the string of parentheses: ");
    scanf("%s", s);

    n = strlen(s);

    printf("The count of valid parentheses pairs is: %d\n", countValidParentheses(s, n));

    return 0;
}
