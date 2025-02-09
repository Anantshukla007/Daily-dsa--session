/*-> Given an array of size ‘N’; find the number of ways to partition it such that sum of each part is <=M ; 
*/

/*The trick is that the formula will always be dependent on the last partition of array 

General Formula:->

dp[i] = you fix the last number “i” + dp[i-1] (the number ways to divide the the start part i-1 of size i-1)
*/


#include<bits/stdc++.h>
using namespace std;

int dp[105];

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;

    for(int i=1;i<=n;i++){
        cin>>b[i];
    }

    dp[0]=1;
    dp[1]=1;

    for(int i=2;i<=n;i++){
        int v=0;
        int j=i;//fix the last psotion 
        int sum=b[i];
        while(j>=1 && sum<=m){
            int g=dp[j-1];//get all the best previous partition solution
            v=v+g;
            j--;
            sum+=b[j];
        }

        dp[i]=v;

    }
    cout<<dp[n];
    return 0;
}