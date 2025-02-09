/*Divide the array in “k” parts such that the sum of all the parts is maximum.

Sum of a part [a1 a2 a3 a4……] = a1 -a2 + a3 -a4…….
*/

/*the fact that k was not given you have to self decide it and for clarity there
were both psositive and negative elements there

now if there were n elements and if all of those were positive we could have
just divide the array in to n parts and make sure the sum becomes maximum

but the catch comes from the negative elements 

now if look closely realize that if we have elements like

a1, -a2, a3, a4 ,a5 

here the way to partition would be 

(a1-(-a2))+a3+a4+a5 see one thing if could just fit the slot of negative element with negative sign we can turn it positive and increase our answer

but how will i make sure that the element at i index element is being a part of negative group and 
and most important thing is to force positive sign on the i-1 element so we will be needing two states for the question

on positive and one negative 

now we will better understand it with the code, I have used k as given because it will become very complex to explain


*/


#include<bits/stdc++.h>
using namespace std;

int divide(vector<int>nums,int k){
    int n=nums.size();
    vector<vector<int>>dp(n+1,vector<int>(2,0));

    for(int i=1;i<=n;i++){
        dp[i][0]=nums[i-1]+max(dp[i-1][0],dp[i-1][1]);
        dp[i][1]=-nums[i-1]+dp[i-1][0];
    }

    return max(dp[n][0],dp[n][1]);

}

int main() {
    vector<int> nums = {1, -2, 3};
    int k = 2;

    int maxSum = divide(nums, k);
    cout << "Ans is "<< maxSum << endl;

    return 0;
}