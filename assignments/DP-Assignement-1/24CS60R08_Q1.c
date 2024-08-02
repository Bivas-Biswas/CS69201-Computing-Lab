#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_split = 0;
int max_substring = -1;
int min_splits = 2000000;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int isValid(char s[], int i, int j, int a[])
{
    int len = j - i + 1;
    for (int k = i; k <= j; k++)
    {
        char c = s[k];
        int x = c - 'a';
        if (len > a[x])
        {
            return 0;
        }
    }

    return 1;
}

void logic(char s[], int i, int n, int a[], int currMaxLen, int currSplits)
{
    if (i == n)
    {
        count_split++;
        max_substring = max(currMaxLen, max_substring);
        if (min_splits == -1 || currSplits < min_splits)
        {
            min_splits = currSplits;
        }
        min_splits = min(min_splits, currSplits);
        return;
    }

    for (int j = i; j < n; j++)
    {
        int len = j - i + 1;

        if (isValid(s, i, j, a))
        {
            currMaxLen = max(len, currMaxLen);
            logic(s, j + 1, n, a, currMaxLen, currSplits + 1);
        }
        else
        {
            break;
        }
    }

    return;
}

int main()
{
    int n;
    char *s;
    int a[26];

    printf("Enter the value of n: ");
    scanf("%d", &n);

    s = (char *)malloc((n + 1) * sizeof(char));

    printf("Enter the string s: ");
    scanf("%s", s);

    printf("Enter 26 integers for the array a:\n");
    for (int i = 0; i < 26; i++)
    {
        scanf("%d", &a[i]);
    }

    logic(s, 0, n, a, -1, 0);
    printf("Number of valid splits: %d\n", count_split);
    printf("Maximum length of a valid substring: %d\n", max_substring);
    printf("Minimum number of substrings: %d\n", min_splits);
}