#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int target;

    cin>>n;

    vector<int>nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    bool flag=1;
    int l=0;
    int r=n-1;
    while(l<=r){
        int mid=(l+r)/2;

        if(nums[mid]==target){
            cout<<mid<<endl;
            flag=0;
            break;

        }
        else if(nums[l]<= nums[mid]){
            if(target>=nums[l] && nums[mid]>=target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
            
        }
        else{
            if(target>=nums[mid]&& target<=nums[r]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
    }

    if(flag==1){
        cout<<-1<<endl;

    }
}