/*Find the minimum cost to do this  : In one operation ; you must select two adjacent numbers ; and merge them to 1 number ; the cost of doing so is the sum of both numbers ; do this till the array has only 1 number left. Find the min cost to do please. 

[5,5,8] = [10,8] = [18] = cost = 10 + 18 
[5,5,8] = [5,13] = [18] = cost = 13 + 18 

Answer is 10 + 18 as it's the way with min cost. 
*/

/*now this question is a vaiation of the subarray dp problem and it will teach you a new pattern 

you must have seen this type of problem in leetcode

lets see what we can look in to this problem


Observation 0 :- Final number in the array will always be the sum of all the numbers. 

it's not the minimum answer so dont confuse it with that but eventuall adding all  numbers of thisarray will sum uo to this right 

now like the last google problem where we were fixing the stick here also we 
are going to fix the stick in a range i to j and compute the answer according to it

now whenever you fix the stcik let say at position k then ans for that subarray is nothin more then that dp[i][k]+dp[k+1][j]+sum(i,j)


but what will be the base case here if we make subarray if size 1 then the dp[i][i] will be zero what will you merge when you have a single element only

ok what if you have two element then the only answer would be the sum of those two right 

lets code and better understand it


*/


#include<bits/stdc++.h>
using namespace std;

int b[20005];
int prefix=[20005];

int sum(int i,int j){
    int topg=prefix[j]-prefix[i-1];
    return topg;
}


int main(){
    int n;
    cin>>n;

    int i=1;
    while(i<=n){
        cin>>b[i];
        prefix[i]=prefix[i-1]+b[i];//precomputing sum to avoid clutter
        i++;
    }

    int dp[n+5][n+5];

    i=1;
    while(i<=n){
        dp[i][i]=0;
        i++;
    }

    i=1;
    while(i<=n-1){
        dp[i][i+1]=b[i]+b[i+1];
        i++;
    }

    int length=3;
    while(length<=n){
        i=1;//setting i to 1
        int j=i+length-1;//setting j to the end length
        while(j<=n){
            int ii=INT_MAX;
            int k=i;
            while(k<=j-1){
                int possibility=dp[i][k]+dp[k+1][j]+sum(i,j);

                ii=min(possibility,ii);
                k++;//moving the stick in the subarray

            }
            dp[i][j]=ii;

            i++;
            j++;

        }

        length++;
    }
    cout<<dp[1][n];

    return 0;
}