/*You are given an array with unique elements of stalls[], which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

Examples :

Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.*/


//now we want the distance  such that the minimum distance between any two of them is the maximum possible.


//but how to know this distnce i can't guess it right no i can the maximum of this dicstace would lie between the range 0 to last stall-first stall postion just serch in that range and we will have our answer

//now for this searchin  i will use binary search simple


#include<bits/stdc++.h>
using namespace std;

bool minimumdistance(int mid, int k, vector<int>stalls){
    int lastposition=stalls[0];
    k--;
    for(int stall=1;stall<stalls.size();stall++){
        int currentposition=stalls[stall];
        if(currentposition-lastposition>=mid){//if the distance betweent the two stalls is greater then or equal to my distance range
            k--;
            lastposition=currentposition
           


        }
        if(k==0){
            return true;
        }
        return false;
    }
}

int aggressivecows(vector<int>stalls,int k){
    sort(stalls.begin(),stalls.end());
    int n=stalls.size();

    int l=1;
    int r=stalls[n-1];-stalls[0];
    int ans=r;

    while(l<=r){
        int mid=(l+r)/2;
        if(minimumdistance(mid,k,stalls)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;

        }
    }
    return ans;

}


int main(){

    int n,k;
    cin>>n;
    vector<int>stalls(n);
    for(int i=0;i<n;i++){
        cin>>stalls[i];
    }
    cin>>k;
    cout<<aggressivecows(stalls,k)<<endl;

}