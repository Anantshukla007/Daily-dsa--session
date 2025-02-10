/*Understanding :-> You are given an array ; divide that array into subarrays ; total cost of doing this should be minimum. 

Whenever the subarray size >=2 ; cost of the subarray [i….j] = b[i] + b[i+1] + ……..b[j] 

Whenever the subarray size = 1 ; cost of the subarray is [i…i] = a[i] 
*/


#include<bits/stdc++.h>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int>a(n+1),b(n+1);

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=n;i++){
        cin>>b[i];
    }


    vector<int>pb(n+1,0);

    for(int i=1;i<=n;i++){
        pb[i]=pb[i-1]+b[i];
    }

    vector<int>dp(n+1,0);

    dp[0]=0; // Base: No elements, cost = 0.
    dp[1]=a[1];// Base: For one element, only the a-cost is allowed.

    int inf=1e18;

    for(int i=2;i<=n;i++){
        int costsingle=dp[i-1]+a[i];
        int costgrp=1e18;

        for(int j=0;j<=i-2;j++){
            costgrp=min(costgrp,dp[j]+(pb[i]-pb[j]);

        }
        dp[i]=min(costsingle,costgrp);
    }

    cout<<dp[n]<<'\n';
    return 0;
}