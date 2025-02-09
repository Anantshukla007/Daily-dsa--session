/*Problem :- You are given an array of size “N” ; you have to start your journey at index “1” and you need to end your journey at index “N”. 

You can make jumps of size - 1 or 3 or 5 

In the array positive as well as negative numbers can be available. 

Please find the maximum sum of journey 

[5 8 3 100 -5 -5 5 10] 

O/P - 131 

*/


#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int b[n+1]={0};
    int dp[n+1]={0};

    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    //base cases till the index five

    dp[1]=b[1];
    dp[2]=b[1]+b[2];
    dp[3]= b[1]+b[2]+b[3];
    dp[4]=max(dp[1]+b[4] ,dp[3]+b[4]);
    dp[5]=max(dp[4]+b[5], (dp[2]+b[5]));

    for(int i=6;i<=n;i++){
        dp[i]=max(dp[i-1]+b[i], max(dp[i-3]+b[i], dp[i-5]+b[i]));

    }

    cout<<dp[n]<<endl;
    return 0;
}
