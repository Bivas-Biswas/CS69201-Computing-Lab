#include <stdio.h>
#include <string.h>

// The main recursive function to print all possible strings of length k
void printAllKLengthRec(char set[], char prefix[], int n, int k, int prefixLength)
{
    // Base case: k is 0, print prefix
    if (k == 0)
    {
        prefix[prefixLength] = '\0'; // Null-terminate the string
        printf("%s\n", prefix);
        return;
    }
    int length = strlen(prefix);

    // One by one add all characters from set and recursively call for k equals to k-1
    for (int i = 0; i < n; i++)
    {
        if (length != 0 && prefix[prefixLength - 1] == set[i])
        {
            continue;
        }

        prefix[prefixLength] = set[i];
        printAllKLengthRec(set, prefix, n, k - 1, prefixLength + 1);
    }
}

    // Function to start the recursive generation of strings
    void printAllKLength(char set[], int k, int n)
    {
        char prefix[k + 1]; // Array to store the prefix, +1 for null terminator
        printAllKLengthRec(set, prefix, n, k, 0);
    }

    // Driver Code
    int main()
    {
        char set1[] = {'a', 'b', 'c'};
        int k = 4;
        int setLen = sizeof(set1) / sizeof(set1[0]);

        printAllKLength(set1, k, setLen);

        return 0;
    }
