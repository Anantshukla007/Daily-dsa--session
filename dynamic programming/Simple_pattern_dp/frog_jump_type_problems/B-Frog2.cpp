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
i, jump to one of the following: Stone 
i+1,i+2,…,i+K. Here, a cost of 
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


/*now this is the follow up to a-forg poblem here the only point is that instead of jump of size 1 and 2 
we will be jumping anywwhere between 1 to k and we have to find best answer withe these jumps
 */


 #include<bits/stdc++.h>
 using namespace std;

 int main(){

    int n;

    cin>>n;
    int k;
    cin>>k;

    int i=1;
    while(i<=n){
        cin>>b[i];
        i++;
    }

    int dp[n+1]={0};
    dp[1]=0;
    dp[2]=abs(b[1]-b[2]);

    i=3;
    while(i<=n){
        int answer=1e18;
        int j=1;//trying all the jumps from size 1 to k
        while(j<=k && i-j>=1){
            int yy= dp[i-j]+abs(b[i]-b[i-j]);
            answer=min(answer,yy);//stroing the best anwer for this index
            j++;
        }
        i++;
    }
    cout<<dp[n];
    return 0;
 }