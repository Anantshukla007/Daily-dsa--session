/*Given a string s of length n, the task is to count number of palindromic subsequence (need not necessarily be distinct) present in the string s.

Example:

Input: s = “abcd”
Output: 4
Explanation: Palindromic subsequence are : “a” ,”b”, “c” ,”d”


Input: s = “aab”
Output: 4
Explanation: palindromic subsequence are :”a”, “a”, “b”, “aa”


Input: s = “geeksforgeeks”
Output: 81*/



//simple and similar to the first basic question but the code is much cleaner here

#include<bits/stdc++.h>
using namespace std;

int dp[500][500];

int main(){
    string s;
    cin>>s;

    int i,j,k;

    i=0;
    while(i<n){
        dp[i][i]=1;
        i++;
    }

    i=0;
    while(i<n-1){
        if(s[i]==s[i+1]){
            dp[i][i+1]=3;//if there are two similar elements that are adjacent to each other then it's count is 3 example aa=>a, a, aa three answers here
        }
        else{
            dp[i][i+1]=2;//else only two ab=> a,b

        }
    }

    int length=3;

    while(legnth<=n){
        i=0;
        while(i<n-legnth+1){
            int j=i+legnth-1;

            if(s[i]!=s[j]){
                dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1]//why subtract the dp[i+1][j-1] because it is getting added twice to the anwer and to avoid recounting of it we subtract it
            }
            else{
                dp[i][j]=1+dp[i][j-1]+dp[i+1][j];
            }

            i++;
        }
        legnth++;
    }
    cout<<dp[0][n-1];
    return 0;
}