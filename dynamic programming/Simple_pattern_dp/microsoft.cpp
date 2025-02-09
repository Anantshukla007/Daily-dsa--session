/*Find the number of ways to make sum “y” with the numbers “1”,”2”,”4”,”6”. 

Condition :- 4 can be used at most 2 times. 
*/


#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;

    if(n==0){
        cout<<3<<endl;
        return 0;
    }


    vector<vector<int>>dp(n+1,vector<int>(3,0));

    dp[0][0]=1;

    for(int i=1;i<=1;i++){
        if(i-1>=0)dp[i][0]+=dp[i-1][0];//case where we use no foru to achieve the sum
        if(i-2>=0)dp[i][0]+=dp[i-2][0];
        if(i-6>=0)dp[i][0]+=dp[i-6][0];


        if(i-1>=0)dp[i][1]+=dp[i-1][1];//nu,ber of ways to achive sum such that we use only one 4
        if(i-2>=0)dp[i][1]+dp[i-2][1];
        if(i-4>=0)dp[i][1]+=dp[i-4][0];//if we are using a single four then in previous we must have not used four
        if(i-6>=0)dp[i][1]+=dp[i-6][1];

        if (i-1 >= 0) dp[i][2] += dp[i-1][2];//case where we use two four to achive the sum
        if (i-2 >= 0) dp[i][2] += dp[i-2][2];
        if (i-4 >= 0) dp[i][2] += dp[i-4][1];//if we are using one four out of two here then we must have used one in previous case
        if (i-6 >= 0) dp[i][2] += dp[i-6][2];




    }



}