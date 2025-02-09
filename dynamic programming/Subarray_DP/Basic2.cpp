/*Given a string str, the task is to find the longest substring which is a palindrome. If there are multiple answers, then return the first appearing substring.

Examples:

Input: str = “forgeeksskeegfor” 
Output: “geeksskeeg”
Explanation: There are several possible palindromic substrings like “kssk”, “ss”, “eeksskee” etc. But the substring “geeksskeeg” is the longest among all.


Input: str = “Geeks” 
Output: “ee”


Input: str = “abc” 
Output: “a”

Input: str = “” 
Output: “”*/


//now this problem is also a foundational problem that is pretty easy use just need to use the basic code template for the subarray problem here and the maximum lenght subarray will be your answer very simple


#include<bits/stdc++.h>
using namespace std;

int dp[500][500];

int main(){
    string s;

    cin>>s;

    int n=s.size();

    int i,j,k;

    i=0;
    int l_palindrome=0;

    while(i<n){
        dp[i][i]=1;
        l_palindrome=1;
        i++;
    }


    i=0;
    while(i<n-1){
        if(s[i]==s[i+1]){
            dp[i][i+1]=1;
            l_palindrome=2;


        }

        i++;
    }

    int length=3;

    while(length<=n){
        i=0;
        while(i<n-length+1){
            int j=i+length-1;

            if(s[i]==s[j] && dp[i+1][j-1]==1){
                dp[i][j]=1;

                l_palindrome=length;
            }

            i++;
        }

        length++;
    }
    cout<<l_palindrome;


}