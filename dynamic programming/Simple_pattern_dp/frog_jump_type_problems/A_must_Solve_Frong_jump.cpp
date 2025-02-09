/*An array of costs was given.
Explain
You always start at index 1.
You can either take two jumps forward or one jump backward. If you land on a particular index, you h
ave to add the cost to your total.
Find the minimum cost needed to cross the array or reach the end of the array.
You can visit any index for only 1 time.
b=[2,5,8]*/


/*now like if any other frog jump problem if it was a simple forward
jump we could have easily solved it right but the issue here is the backward jump you cant be storing that state how will you do it?

so first obesrvation like normal forward jump problems this problem has two differnt jump states forward 
and backward so we will be using a 2d array 


now the second obesrvation and key point to note is that we can visit any index only once 

now consider a case simple case 

[1,2,3,4,5,6];

now if from one you forward jump then you will reach the index 3 now from three if you jump back you go to index 2 right

but after reaching index two you can only make forward jump no backward jump possible because one is already visited 

so a key observation is that you can not make two consicutive backward jumps 


now lets create a 2d dp dp[index][forward] ways
dp[index][backward] ways

now we wil understand the logic with the code

in any interview you must figure out this much logic 

*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int b[n+1]={0};

    int i=1;
    while(i<=n){
        cin>>b[i];
        i++;
    }

    int dp[n+1][5];
    dp[1][2]=b[1];//cost of coming at index 1 by  a forward jump
    dp[1][1]=1000000000;//there is no where to jump back  to index 1 so make it is infinity 

    dp[2][2]=1000000000;//you can not come at index 2 by any forward jump so this cost 

    dp[2][1]=dp[1][2]+b[2]+b[3]// you can reach index two by a backward jump from index three so cost of forward jump at 1+ cost of 3 +cost of 2


    i=3;
    while(i<=n-1){
        dp[i][2]=b[i]+min(dp[i-2][1],dp[i-2][2]);//incase we are asking for the cost of reaching index i by forward jump in such case we sahll check both the backward and forward jump ways at i-2 beacuse both option are available
        dp[i][1]=b[i]+b[i+1]+dp[i-1][2];//only one way here 
        i++;

    }


    //special case as we either want to jump outside or at the last position so safely handling them seprately
    

    dp[i][2]=b[n]+min(dp[i-2][2],dp[i-2][1]);
    dp[i][1]=10000000;
    cout<<min(dp[n][2],min(dp[n-1][2],dp[n-1][1]));

    return 0;
}