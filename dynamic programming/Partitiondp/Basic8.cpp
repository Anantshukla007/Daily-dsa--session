/*Given an array of size “N” ; you can do a particular type of operation any number of times(even 0) ; the final size of the array should be as small as possible! 

In one operation ; you are allowed to pick any subarray which starts and ends at the same element and remove it from array 
*/


/*ans[i] = best answer to the question if array is from index 1 to index i 

dp[i][0] = best answer to the question if the array is from index 1 to index i and index “i” has not been selected as the right end point of any range! :-) 

dp[i][1] = best answer to the question if the array is from index 1 to index i and index “i” has been selected as the right end point of some range! 

 ans[i] = min(dp[i][0],dp[i][1]) 
*/

#include<bits/stdc++.h>
using namespace std;

int dp[50000][2];
int ans[50000];

int main(){

    int n;
    cin>>n;
    int b[n+1]={0};

    for(int i=1;i<=n;i++){
        cin>>b[i];

    }

    dp[1][0]=1;
    dp[1][1]=1e8;

    ans[1]=min(dp[1][0],dp[1][1]);

    for(int i=2;i<=n;i++){
        dp[i][0]=1+ans[i-1];

        int v=1e8;

        int j=i-1;
        while(j>=1){
            if(b[i]==b[j]){
                v=min(v,ans[j-1]);
            }
            j--;
        }

        dp[i][1]=v;

        ans[i]=min(dp[i][0],dp[i][1]);

    }
    cout<<min(dp[n][0],dp[n][1]);
    return 0;



}