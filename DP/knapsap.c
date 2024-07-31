#include <stdio.h>

void swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

int clause1(float weights[], float values[], int n, int capacity)
{
    float unitValues[n];

    // calculate unit values
    for (int i = 0; i < n; i++)
    {
        float d = values[i] / weights[i];
        unitValues[i] = d;
    }

    // sort
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (unitValues[j] < unitValues[j + 1])
            {
                swap(&unitValues[j], &unitValues[j + 1]);
                swap(&weights[j], &weights[j + 1]);
                swap(&values[j], &values[j + 1]);
            }
        }
    }

    // calculate
    float resultValue = 0;
    float totalCapacity = 0;

    for (int i = 0; i < n; i++)
    {
        float remainCapacity = capacity - totalCapacity;

        if (remainCapacity <= 0)
        {
            break;
        }
        else
        {

            if (weights[i] > remainCapacity)
            {
                float fraction = remainCapacity / weights[i];
                resultValue += fraction * values[i];
                totalCapacity += fraction * weights[i];
            }
            else
            {
                resultValue += values[i];
                totalCapacity += weights[i];
            }
        }
    }

    return resultValue;
}

int clause2(float weights[], float values[], int n, int capacity)
{
    float unitValues[n];

    // calculate unit values
    for (int i = 0; i < n; i++)
    {
        float d = values[i] / weights[i];
        unitValues[i] = d;
    }

    // sort
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (unitValues[j] < unitValues[j + 1])
            {
                swap(&unitValues[j], &unitValues[j + 1]);
                swap(&weights[j], &weights[j + 1]);
                swap(&values[j], &values[j + 1]);
            }
        }
    }

    // calculate
    float resultValue = 0;
    float totalCapacity = 0;

    for (int i = 0; i < n; i++)
    {
        float remainCapacity = capacity - totalCapacity;

        if (remainCapacity <= 0)
        {
            break;
        }
        else
        {

            if (weights[i] < remainCapacity)
            {
                resultValue += values[i];
                totalCapacity += weights[i];
            }
        }
    }

    return resultValue;
}

float max(float x, float y)
{
    if (x > y)
    {
        return x;
    }

    return y;
}

int clause3(float weights[], float values[], int n, int capacity, int idx)
{
    if (idx == n)
    {
        return 0;
    }
    else
    {
        int took = 0, notTook = 0;
        notTook = clause3(weights, values, n, capacity, idx + 1);

        if (weights[idx] <= capacity)
        {
            took = values[idx] + clause3(weights, values, n, capacity - weights[idx], idx + 1);
        }

        return max(notTook, took);
    }
}

int clause4DP(float weights[], float values[], int n, int currentCapacity, int capacity, int idx, float dp[n][capacity + 1])
{

    if (idx == n)
    {
        return 0;
    }
    if (dp[idx][currentCapacity] != -1)
    {
        return dp[idx][currentCapacity];
    }

    int took = 0, notTook = 0;
    notTook = clause4DP(weights, values, n, currentCapacity,capacity, idx + 1, dp);

    if (weights[idx] <= currentCapacity)
    {
        took = values[idx] + clause4DP(weights, values, n, currentCapacity - weights[idx], capacity, idx + 1, dp);
    }

    dp[idx][currentCapacity] = max(notTook, took);

    return dp[idx][currentCapacity];
}

int clause4(float weights[], float values[], int n, int capacity)
{
    float dp[n][capacity + 1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            dp[i][j] = -1;
        }
    }
    clause4DP(weights, values, n, capacity, capacity, 0, dp);
}

void main()
{
    float values[] = {100, 30, 35, 90};
    float weights[] = {25, 10, 12, 15};
    int n = 4;
    int capacity = 30;

    // franctional -> gredy
    printf("Clause 1 : %d \n", clause1(weights, values, n, capacity));

    // 0 / 1 -> gredy but not optimal
    printf("Clause 2 : %d \n", clause2(weights, values, n, capacity));

    // 0 / 1 -> recursion all possible subset
    printf("Clause 3 : %d \n", clause3(weights, values, n, capacity, 0));

    // 0 / 1 -> using memoization
    printf("Clause 4 : %d \n", clause4(weights, values, n, capacity));
}