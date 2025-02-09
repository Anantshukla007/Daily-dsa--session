/*There are 
N stones, numbered 
1,2,…,N. For each 
i (
1≤i≤N), the height of Stone 
i is 
h 
i
​
 .

There is a frog who is initially on Stone 
1. He will repeat the following action some number of times to reach Stone 
N:

If the frog is currently on Stone 
i, jump to Stone 
i+1 or Stone 
i+2. Here, a cost of 
∣h 
i
​
 −h 
j
​
 ∣ is incurred, where 
j is the stone to land on.
Find the minimum possible total cost incurred before the frog reaches Stone 
N.*/

//similar to the amazon ml school problem just same code can be used here also


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int b[n+1]={0};
    while(i<=n){
        cin>>b[i];
        i++;
    }

    int dp[n+1]={0};
    dp[1]=0;//stading at first position then answer is automatically 0
    dp[2]=abs(b[1]-b[2]);//for the second position this is the only answer

    i=3;
    while(i<=n){
        dp[i]=min(dp[i-1]+abs(b[i]-b[i-1]), dp[i-2]+abs(b[i]-b[i-2]));
        i++;
    }

    cout<<dp[n];
    return 0;
}