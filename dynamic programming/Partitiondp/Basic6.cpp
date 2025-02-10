/*Given an array such that all number can be positive as well as negative; 
Pick some subarrays[they should not overlap] ; size of each subarray = m; once you have picked all your subarrays ; please calculate their sum. 

Your task is to maximize the sum.


it is fixed that you should select exactly k subarrays;
*/


#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr, int m, int k) {
    int n = arr.size();

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0)); // Initialize dp array
    vector<int> prefixSum(n + 1, 0);

    // Compute prefix sum
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }

    // DP calculation
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][j]; // Default: Do not take current subarray

            if (i >= m) { 
                dp[i][j] = max(dp[i][j], prefixSum[i] - prefixSum[i - m] + dp[i - m][j - 1]);
            }
        }
    }

    return dp[n][k];
}

//you can write the main your self