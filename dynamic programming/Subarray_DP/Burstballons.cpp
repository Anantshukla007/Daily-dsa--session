/*You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

 

Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
Example 2:

Input: nums = [1,5]
Output: 10*/


int maxCoins(vector<int>b){
    int n=b.size();
    vector<int>g;
    g.push_back(1);
    int i=0;
    while(i<n){
        g.push_back(b[i]);
        i++;
    }
    g.push_back(1);

    vector<vector<int>>dp(n+5,vector<int>(n+5,0));

    i=1;
    while(i<=n){
        dp[i][i]=g[i-1]*g[i]*g[i+1];

        i++;
    }


    int length=2;

    while(length<=n){
        i=1;
        int j=i+length-1;

        while(j<=n){
            int ii=INT_MIN;

            int k=i;
            while(k<=j){
                int poss=g[i-1]*g[i]*g[j+1];

                if(i<=k-1){
                    poss+=(dp[i][k-1]);
                }
                if(k+1<=j){
                    poss=dp[k+1][j]
                }

                ii=max(ii,poss);
                k++;
            }

            dp[i][j]=ii;
            i++;
            j++;
        }
        length++;
    }
    return dp[1][n];

}