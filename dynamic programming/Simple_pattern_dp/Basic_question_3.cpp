/*We are given ‘2’ arrays . Select some elements from both of these arrays (select a subset) such that:-

--->1. Sum of those elements is maximum(Sum of the subset is maximum).
No 2 elements in the subset should be consecutive*/


#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int a1[n];
    for(int i=1;i<=n;i++){
        cin>>a1[i];
    }

    for(int i=1;i<=n;i++){
        cin>>a2[i];
    }

    int dp[n+1]={0};

    dp[1]=max(a1[1], a2[1]);//

    dp[2]=max(dp[1],max( a1[2], a2[2] ));

    int i=3;
    while(i<=n){
        dp[i]=max(max(a1[i] , a2[i])+dp[i-2], dp[i-1]);
        i++;
    }
    cout<<dp[n];
    return 0;
}