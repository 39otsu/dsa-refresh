#include <stdio.h>

int coinChange(int size, int * arr, int amount);

int main()
{
    int size = 3;
    int amount = 5;
    int arr[3] = { 1, 2, 5};
    unsigned int ways = coinChange(size, arr, amount);
    printf("There are %u ways to make amount %d using the provided values.\n", ways, amount);

    return 0;
}

int coinChange(int size, int * arr, int amount) {
    
    int dp[amount + 1];
    dp[0] = 1;
    
    for (int i = 0; i < size; i++) {
        int coin = arr[i];
        for (int j = 0; j <= amount; j++) {
            dp[j] += dp[j - coin];
        }
    }
    
    return dp[amount];
}