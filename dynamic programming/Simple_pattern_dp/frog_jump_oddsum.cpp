/*Find the number of journeys where you start from index 1 and end at index ‘n’ and the sum of every journey should be odd..

Allowed to make jumps of size 1 or 2 
5 4 2 6 

Number of odd sum journey : 
-> (5,2,6)
-> (5,4,2,6)
-> (5,4,6)
*/

/*in dp question if you are not ablue to visualize the dp you should thake
more states as per the need and you might be able to reduce the state after solving
with more states */

#include<bits.stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;

    int a[n+1]={0};
    int i=1;
    while(i<=n){
        cin>>a[i];
        i++;
    }

    //dp[i][1]=> number of journeys till index i whose sum is odd
    //dp[i][2]=> number of journeys till index i whose sum is even

    if(a[1]%2==0){//if first element is even then at first index the answer would be one
        dp[1][2]=1;
    }
    else{
        dp[1][1]=1;//if it is odd
    }
    i=2;

    while(i<=n){
        if(a[i]%2==0){//if current element is even 
            dp[i][2]=dp[i-1][2]+dp[i-2][2];//increase the even journeys by even 
            dp[i][1]=dp[i-1][1]+dp[i-2][2];
        }
        else{//if odd
            dp[i][2]=dp[i-1][1]+dp[i-2][1];
            dp[i][1]=dp[i-1][2]+dp[i-2][2];
        }
        i++;
    }

    cout<<dp[n][1]<<" "<<dp[n][2];
    return 0;

}