/*Understanding :-> You are given 2 arrays 
travel from start to end; maximum maximum dollars
whenever you try to jump from Array “A” to Array “B” you make no money :) 
*/


/*now like normal question we could have stored the best solution till any index and then we can just use the stored 
solution but there is a catch the issue is that we can jump from 
one array to another and at any index we need to know the best solution by taking element from
either array a or array b 

now when you consider that at previous index you made jump then 
that previous element answer is to be skipped and use the solution from the 


-> dp[i][a] = best answer to the question if size of both array were “i” and the element picked at the ith index if for sure from array “a”

-> dp[i][b] = best answer to the question if size of both array were i and element picked at ith index is from B

dp[i][a] = max(a[i] + dp[i-1][a] Or a[i] + dp[i-2][b]) 

dp[i][b] = max(b[i] + dp[i-1][b] or b[i] + dp[i-2][a]) 

*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int a[n+1]={0};
    int b[n+1]={0};

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=n;i++){
        cin>>b[i];
    }

    int dp[10000][2];

    dp[1][0]=a[1];
    dp[1][1]=b[1];

    for(int i=2;i<=n;i++){
        dp[i][0]=max(dp[i-1][0]+a[i],dp[i-2][1]+a[i]);

        dp[i][1]=max(dp[i-1][1]+b[i],dp[i-2][0]+b[i]);
    }

    cout<<dp[n][0]<<" "<<dp[n][1];

    return 0;

}