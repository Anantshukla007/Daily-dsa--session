/*You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];

    }
    int l=0;
    int r=n-1;
    while(l<r){
        int mid=(l+r)/2;
        if((mid%2 && nums[mid]==nums[mid-1])  ||  (mid%2==0 && nums[mid]==nums[mid+1])){
            ;=mid+1;
        }
        else{
            r=mid;
        }
    }
    cout<<nums[l]<<endl;
}