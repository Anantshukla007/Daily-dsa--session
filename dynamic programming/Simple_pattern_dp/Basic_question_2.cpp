/*Understanding this problem and its solution properly will make a strong foundation for you in the DP world! (This worked for me :-) )

Here we go :   Given an array of integers(positive as well as negative) ,select some elements from this array(select a subset) such that:-


1. Sum of those elements is maximum(Sum of the subset is maximum) .

2. No two elements in the subset should be consecutive.

Example :- {2,4,6,7,8}

Answer:- {2+6+8=16}*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];

    }
    int dp[n+1]={0};

    dp[1]=max(a[1],0);//base case 1 when first element
    dp[2]=max(a[2],dp[1]);//base case second when you pick the second element

    int i=3;
    while(i<=n){
        dp[i]=max(a[i]+dp[i-2], dp[i-1]);
        i++;

    }
    cout<<dp[n];

    return 0;


}