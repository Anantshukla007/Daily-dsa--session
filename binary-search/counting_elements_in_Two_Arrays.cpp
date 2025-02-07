/*You are given two unsorted arrays a[] and b[]. Both arrays may contain duplicate elements. For each element in a[], your task is to count how many elements in b[] are less than or equal to that element.

Examples:

Input: a[] = [1, 2, 3, 4, 7, 9], b = [0, 1, 2, 1, 1, 4]
Output: [4, 5, 5, 6, 6, 6]
Explanation: 
For a[0] = 1, there are 4 elements in b (0, 1, 1, 1) that are ≤ 1.
For a[1] = 2, there are 5 elements in b (0, 1, 1, 1, 2) that are ≤ 2.
For a[2] = 3, there are 5 elements in b that are ≤ 3.
Similarly, for a[3] = 4, there are 6 elements in b that are ≤ 4, and for a[4] = 7 and a[5] = 9, there are also 6 elements in b that are ≤ 7 and ≤ 9, respectively*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int m;
    int n;
    cin>>m>>n;

    vector<int>arr1;
    vector<int>arr2;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr1.push_back(temp);
    }
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr2.push_back(temp);
    }

    vector<int>ans;

    sort(arr2.begin(),arr.end())//just sort the second array and find the upper bound of the array

    for(int i=0;i<m;i++){
        int idx=upper_bound(arr2.begin(),arr2.end(),arr1[i])-arr2.begin();
        idx--;
        ans.push_back(idx-0+1);

    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";

    }
    return 0;
}