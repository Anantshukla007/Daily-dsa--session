/*Minimum Cost to Reach the Destination
There are N cities in a country. George is initially at the airport in city 1 and he wants to reach city N. For any city i, there is either a flight to city (i+1) or to (i+3) if it exists.
You have been given an array A with the costs of flight tickets for N cities. To find the cost of a flight ticket between any two cities i and j, you take the absolute difference of the costs of those cities in the array A. You can use the formula la Cost[i]- Cost[j]| to calculate the cost of a flight ticket, where lal represents the absolute value of a.
Your task is to find and return the minimum possible cost of flight ticket required to reach the city N.
Note:
• The number of cities is always greater than 3.
Assume 1 based indexing*/


/* this is also a simple problem and you will see many variation of this same problem*/


#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<int>cost(n+1);
    vector<int>dp(n+1,0);
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }

    //the base case will be zero as we don't need any cost to reach  the first position where we are already standing
    dp[1]=0;
    dp[2]=abs(cost[2]-cost[1]);//pretty simple the doing what being said in the problem

    dp[3]=dp[2]+abs(cost[2]-cost[3]);

    for(int i=4;i<=n;i++){
        dp[i]=min(abs(cost[i]-cost[i-1])+dp[i-1] , abs(cost[i]-cost[i-3]+dp[i-3]));//basic what is asked we can only make two different types of jump 
        cout<<dp[i];
        cout<<'\n';
    }
    cout<<dp[n]<<endl;
    return 0;
}