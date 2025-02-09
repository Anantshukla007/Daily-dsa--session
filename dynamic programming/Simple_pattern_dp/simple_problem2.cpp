/*You are given a positive integer 'N’. Your task is to find and return the minimum number of steps that 'N' has to take to get reduced to 1. 
You can perform any one of the following 3 steps:
1) Subtract 1 from it. (n = n - ­1) ,
2) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int dp[n+1]={0};

    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    dp[4]=2;

    for(int i=5;i<=n;i++){
        int p1=1+dp[i-1];
        int p2=INT_MAX;
        int p3=INT_MAX;
        if(i%2==0){
            p2=1+dp[i/2];
        }
        if(i%3==0){
            p3=1+dp[i/3];
        }

        dp[i]=min(p1,min(p2,p3));
    }
    cout<<dp[n]<<endl;
    return 0;
}