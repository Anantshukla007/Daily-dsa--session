/* We are given an array of integers(a[n]) . We are given multiple queries of the form : (1, i) which means we need to output the sum of all numbers from index- ‘1’ to index ‘i’ of the array.

Analysis : Running a loop for each query[O(N)] and finding the sum is a good idea but not very efficient as it takes O(N*Q) time.*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=5;
    int a[5]={6,7,7,8,86};

    int dp[n+1]={0};

    int i=0;
    while(i<=n-1){
        if(i==0){
            dp[i]=a[i];//base case
        }
        else{
            dp[i]=a[i]+dp[i-1];// if we want current sum then we can just use the previous sum 
        }
        i++;
    }

    int q=4;
    int w[4]={0,3,4,2};

    int i=0;
    while(i<=q-1){
        int query;
        query=w[i];
        cout<<dp[query];
        cout<<endl;
        i++;
    }

    return 0;
}


