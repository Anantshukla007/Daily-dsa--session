/*A string is said to be a k-interspace string if the absolute difference of the ASCII values of every pair of adjacent characters is at most For example-"abac" is a k-interspace string for ka 2 since the absolute difference between every adjacent character of it is at most
. A substring is any group of contiguous characters in a string. For example, the substrings of abc (abc, ab, bc, a, b, c). A substring 2 of a string is said to be interspace substring if the substring is a k-interspace string
Given a string, word, and an integer, & find the longest k-interspace substring within word. If there are multiple substrings of the longest length, return the one that occurs first in word
For example:
word-wedding
The first occurring longest interspace substring is dd
word ababbacaabbbb
よって
There are two 7-interspace substrings of length & ababba and aabbbb. The one that occurs first is ababba
Function Description
Complete the function longestKinterspaceSubstring in the editor below.
longest KinterspaceSubstring has the following parameter(s):
string word the string to analyze
int k maximum difference in character values
Returns:
string: the first occurring longest k-interspace substring of the word
Constraints
1sword/10
Osks25
Each character of word ascii[az]*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int k;
    cin>>n>>k;
    string s;
    cin>>s;

    vector<int>dp(n,1);
    int max_len=1;
    int max_index=0;

    for(int i=1;i<n;i++){
        if(abs(s[i]-s[i-1]) <= k){
            dp[i]=dp[i-1]+1;//basic case 
        }
        else{
            dp[i]=1;//if not satisfying the condition then just take 1 as answer there beacuse then that is the maximum for that index
        }

        if(dp[i]>max_len){
            max_len=dp[i];
            max_index=i;
        }


    }

    int start_index=max_index-max_len+1;
    cout<<s.substr(start_index,max_len)<<endl;
    return 0;
}