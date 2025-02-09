/*Understanding - Given an array - divide the array into K-parts. 
G1 = maximum element of the first partition. 

G2 = maximum element of the second partition.

.
.
.
.
.
GK = maximum element of the last partition. 

Make sure (G1+G2+G3+G4+G5+........GK) is minimized. 
*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int solve(vector<int>arr, int n , int k){
    vector<vector<int>>dp(n+1,vector<int>(k+1,INT_MAX));

    for(int i=0;i<=k;i++){
        dp[0][i]=0;

    }

    for(int i=1;i<=n;i++){
        for(int part=1;part<=k;part++){

            int currmax=0;

            for(int j=i;j>=1;j--){
                currmax=max(currmax,arr[j-1]);
                if(dp[j-1][parts-1]!=INT_MAX){
                    dp[i][parts]=min(dp[i][parts], currmax+dp[j-1][parts-1]);
                }

            }
        }
    }

    return dp[n][k];
}

int main() {
    int n, k;
    cin >> n;
    cin >> k;
 
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
 
    int result = solve(arr, n, k);
    cout << "Minimum sum of maximum elements of each partition: " << result << endl;
 
    return 0;
}