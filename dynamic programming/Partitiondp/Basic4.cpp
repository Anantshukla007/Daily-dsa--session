/*The problem is finding the maximum number of ways to divide an array into "good subarrays". The conditions for a good subarray are:

Each subarray should contain at least two elements.
The cost of each subarray should be minimized.
A partition is valid if it ends at an index where the left greater element exists.
The number of partitions should be maximized.*/



/*optimized solution*/
#include<bits/stdc++.h>
using namespace std;


vector<int>findleftgreater(vector<int>b){
    int n=b.size();
    vector<int>left(n,-1);

    stack<int>s;

    for(int i=1;i<n;i++){
        while(!s.empty() &&b[s.top()]<=b[i]){
            s.pop();
        }
        left[i]=s.empty()?-1:s.top();

        s.push(i);
    }

    return left;
}


int max_Way( vector<int>b){
    int n=b.size();
    vector<int>dp(n+1,0);
    vector<int>left=findleftgreater(b);

    vector<int>prefix_dp(n+1);

    prefix_dp[0]=dp[0];

    for(int i=1;i<=n;i++){
        if(left[i]!=-1){
            int u=left[i];
            if(u+1==i){
                dp[i]=prefix_dp[i-2]+;
            }

            else{
                dp[i]=prefix_dp[u]+1;
            }
        }

        prefix_dp[i]=max(prefix_dp[i-1],dp[i]);
    }

    return dp[n];
}

int main(){
    vector<int> b = {0, 3, 1, 4, 6, 5, 2};
    int d=max_Way(b);
    cout<<d<<endl;
    return 0;

}



/*basic solution*/

/*
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& arr, int start, int end) {
    // Check if the subarray arr[start:end+1] is "good"
    // A "good" subarray doesn't have its maximum element at the end

    int max_elem = arr[start]; // Initialize max_elem with the first element in the subarray
    for (int i = start + 1; i <= end; ++i) {
        if (arr[i] > max_elem) {
            max_elem = arr[i];
        }
    }

    // Check if the maximum element of the subarray is not at the end position
    if (arr[end] != max_elem) {
        return true; // Subarray is "good"
    } else {
        return false; // Subarray is not "good"
    }
}

long long int max_ways_to_divide(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;

    vector<long long int> dp(n, 0); // dp array to store maximum number of ways to divide

    for (int i = 1; i <= n-1; ++i) {
        for (int j = i; j >= 1; --j) {
            if (check(arr,j,i)) {
                if (j == 1) {
                    dp[i] = max(dp[i], 1LL);
                } else if (dp[j - 1] >= 1) {
                    dp[i] = max(dp[i], 1LL + dp[j - 1]);
                }
            }
        }
        cout<<i<<" "<<dp[i]<<"\n";
    }

    return dp[n-1];
}

int main() {
    vector<int> arr = {0, 1, 4, 6, 5, 2};
    //arr[0] is dummy value because we are using 1 based indexing
    long long int max_ways = max_ways_to_divide(arr);

    cout << "Maximum number of ways to divide into good subarrays: " << max_ways << endl;

    return 0;
}
*/