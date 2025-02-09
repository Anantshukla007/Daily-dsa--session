/*palidrmoic substrings 

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".


Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/


/*while dealing with the subarray problem on thing to keep in mind is that you are dealing with 
continous length array that starts and ends with minimum being 1 to maxium being n 
and you answer is hidden in somwhere between all these lengths

now since we are dealing with the lengths they will have a start as well as the end index that
we need to store in our dp so for this we generally use a 2 -d dp dp[i][j]

and now lets discuss the base cases well every problem has different set of 
tasks to deal wiht but in subarray problem the base case is generallly
precomputing the legth 1 and lenght 2 subarray becasuse they are the easiset to deal 
with so generally you will see that you will require the precomputation of these to 


now we will better understand with the code part
*/


int solve(string s){
    int n=s.size();
    int dp[n+1][n+1];//dp[i][j]

    int res=0;

    for(int length=0;length<n;length++){//traversing the all length subarrays
        for(int i=0,j=length; j<n;i++,j++){

            if(length==0){//base case as subarray of size 1 will always be a plaindrome so true
                dp[i][j]=1;
                res++;
            }

            else if(legth==1){//subarray sized two
                if(s[i]==s[j]){
                    dp[i][j]=1;
                    res++;
                }
            }
            else if(s[i]==s[j] && dp[i+1][j-1]==1){//if the current left and right element are palindromic shrink and check for the next elements
                dp[i][j]=1;
                res++;
            }
        }
    }
    return res; 
}