/*Understanding - You are given a number line from [0…….N] on the X-axis; at each point there is sprinkler and it power is given ; it can throw water from the range [i-r…….i+r] ; you have to select a subset of sprinklers such that you are able to throw water in the whole range [0……n] -> this range should be covered bare minimum necessity 

We have to do this in minimum cost 
*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int power[n+1]={0};
    int cost[n+1]={0};
    int dp[n+1]={0};
    for(int i=0;i<=n;i++){
        cin>>power[i];
    }

    for(int i=1;i<=n;i++){
        int g=1e18;

        int j=i;
        while(j>=0){
            if(power[j]!=0){
                int left=j-power[j];
                int right=j+power[j];

                if(right>=i){
                    int p=1e18;

                    if(left<=0){
                        p=min(p,cost[j]);
                    }
                    else{
                        p=min(p,cost[j]+dp[left]);

                    }

                    g=min(g,p);
                }
            }

            j--;
        }
        dp[i]=g;

        
    }

    if(dp[n]==1e18){
        dp[n]=-1;
    }
    cout<<dp[n]<<endl;
}