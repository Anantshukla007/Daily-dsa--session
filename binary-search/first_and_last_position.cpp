/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109*/

vector<int>searchrange(vector<int>nums,int target){

    vector<int>ans;

    int n=num.size();
    int l=0;
    int r=n-1;
    int first=-1;
    int last=-1;
    while(l<=r){
        int mid=(l+r)/2;

        if(nums[mid]>=target){
            if(nums[mid]==target){
                first=mid;
            }
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }

    ans.push_back(first);

    l=0;
    r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(nums[mid]<=target){
            if(nums[mid]==target){
                last=mid;
            }
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    ans.push_back(last);
    return ans;
}