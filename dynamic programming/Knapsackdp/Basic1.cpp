/*Given N items where each item has some weight and profit associated with it and also given a bag with capacity W, [i.e., the bag can hold at most W weight in it]. The task is to put the items into the bag such that the sum of profits associated with them is the maximum possible. 

Note: The constraint here is we can either put an item completely into the bag or cannot put it at all [It is not possible to put a part of an item into the bag].

Input: N = 3, W = 4, profit[] = {1, 2, 3}, weight[] = {4, 5, 1}
Output: 3
Explanation: There are two items which have weight less than or equal to 4. If we select the item with weight 4, the possible profit is 1. And if we select the item with weight 1, the possible profit is 3. So the maximum possible profit is 3. Note that we cannot put both the items with weight 4 and 1 together as the capacity of the bag is 4.


Input: N = 3, W = 3, profit[] = {1, 2, 3}, weight[] = {4, 5, 6}
Output: 0

*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int w[n+1]={0};
    int p[n+1]={0};

    int i=1;
    while(i<=n){
        cin>>w[i];
        cin>>p[i];

    }


    int dp[n+1][c+1]={0};

    i=0;

    while(i<=c){
        int j=1;
        while(j<=c){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            j++;
        }
        i++;
    }


    i=1;
    while(i<=n){// n elements 
        int j=1;

        while(j<=c){//all cost 
            int not_take=dp[i-1][j];

            int take=0;
            if(j-w[i]>=0){
                take=p[i]+dp[i-1][j-w[i]];

            }

            dp[i][j]=max(not_take,take);
            j++;
        }
        i++;
    }
    cout<<dp[n][c];
    return 0;
}