/*You are given an array of size N name cost[i] ; you are also given happy[i] ; max[i] ; min[i] ; m-> total budget 

Do shopping in such a way such that you get maximum happiness in the given money 
*/


#include<bits/stdc++.h>
using namespace std;

int dp[105][105];

int main(){

    int n;
    cin>>n;

    int cost[n+1]={0};

    int i=1;
    while(i<=n){
        cin>>cost[i];
        i++;
    }

    int happy[n+1]={0};

    while(i<=n){
        cin>>happy[i];
        i++;
    }

    int mn[n+1]={0};
    while(i<=n){
        cin>>mn[i];
    }

    int my[n+1]={0};

    while(i<=n){
        cin>>my[i];
        i++;
    }

    int m;
    cin>>m;

    i=1;
    while(i<105){
        int j=0;
        while(j<105){
            dp[i][j]=-1e18;

            j++;
        }
        i++;
    }


    i=1;
    while(i<=n){

        int j=1;
        while(j<=m){
            int final_answer=-1e18;
            int count=mn[i];
            while(count<=my[i]){
                int g=count*cost[i];

                if(j-g>=0){
                    int answer=dp[i-1][j-g]+count*happy[i];
                    final_answer=max(final_answer,answer);
                }
                count++;
            }
            dp[i][j]=final_answer;
            j++;
        }
        i++;
    }
    cout<<dp[n][m];
    return 0;

}