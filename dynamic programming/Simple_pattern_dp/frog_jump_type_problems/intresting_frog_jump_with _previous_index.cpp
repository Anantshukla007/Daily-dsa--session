/*There are two arrays , 'B' and 'C' ; size of both the arrays is 'N' ;

-> At each index you are supposed to pick up an element either from array 'C' or array 'B'

->You have to maximize the final sum of all elements

->Condition : You cannot select 3 or more than 3 element consecutively from the same array.

Example :

3

5 10

3 10

4 10

Output : 25

1<=N<=100000

1<=B[i];C[i]<=10000000000*/


#include<bits/stdc++.h>
using namesapce std;

int maxi(int x,int y,int z,int g){
    return max(max(x,y),max(z,g));
}

int mx(int x,int y,int z){
    return max(x,max(y,z));
}

int main(){

    int n;
    cin>>n;

    int b[n+1]={0};
    int d[n+1]{0};
    int i=1;
    while(i<=n){
        cin>>b[i];
        cin>>d[i];
        i++;
    }

    int dp[n+1][5][5]={0};

    // dp[index][choice in i-1 index][choice in i index]

    dp[1][1][1]=b[1];
    dp[1][1][2]=d[1];
    dp[1][2][2]=d[1];
    dp[1][2][1]=b[1];

    i=2;
    while(i<=n){
        dp[i][1][1]=b[i]+b[i-1]+max(dp[i-2][2][2],dp[i-2][1][2]);
        dp[i][2][1]=b[i]+d[i-1]+mx(dp[i-2][1][2],dp[i-2][1][1],dp[i-2][2][1]);
        dp[i][1][2]=d[i]+b[i-1]+mx(dp[i-2][2][2],dp[i-2][1][2],dp[i-2][2][1]);
        dp[i][2][2]=d[i]+d[i-1]+max(dp[i-2][1][1],dp[i-2][2][1]);
    }


    cout<<"final answer is "<<maxi(dp[n][1][1],dp[n][1][2],dp[n][2][2],dp[n][2][1]);
    

}
