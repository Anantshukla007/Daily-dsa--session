/*Stephen is doing an internship in a company for N days. Each day, he may choose either an easy task or a difficult task. He may also choose to perform no task at all. He chooses a difficult task on days when and only when he did not perform any work the previous day. The amount paid by the company for both the easy and difficult tasks can vary each day, but the company always pays more for difficult tasks.
Write an algorithm to help Stephen earn the maximum salary.
Input
The first line of the input consists of two space-separated integers - num and type, representing the number of days of the internship (N) and types of tasks available for each day (type (M) is always equal to 2), respectively.
The next N lines consist of M space-separated integers - easy and hard, representing the amount set to be paid for the easy task and the difficult task on that day, respectively.
Output
Print an integer representing the maximum salary that Stephen can earn.*/



#include<bits/stdc++.h>
using namespace std;

int dp[5000][5];

int maxi(int x,int y,int z){
    return max(x,max(y,z));
}


int main(){
    int n,m;
    cin>>n;
    cin>>m;

    int easy[n+1]={0};
    int hard[n+1]={0};

    int i=1;
    while(i<=n){
        cin>>easy[i];
        cin>>hard[i];
        i++;
    }

    dp[1][1]=easy[1];
    dp[1][2]=hard[1];
    dp[1][3]=0;

    i=2;
    while(i<=n){
        dp[i][1]=easy[i]+maxi(dp[i-1][1],dp[i-1][2],dp[i-1][3]);
        dp[i][2]=hard[i]+dp[i-1][3];
        dp[i][3]=0+maxi(dp[i-1][1],dp[i-1][2],dp[i-1][3]);
    }

    cout<<"final answer"maxi(dp[n][1],dp[n][2],dp[n][3])<<endl;

    return 0;
}