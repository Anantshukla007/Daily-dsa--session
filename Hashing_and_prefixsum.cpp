//Check if there are any two Equal numbers in an array at a distance less than or equal to k
//for this type of the question the maina approach is to use two loops but since we want the advance approach we will just use the basic hashing approach

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool containdup(vector<int>nums, int k){
    unordered_map<int,int>mp;
    for(int i=0; i<n;i++){
        if(mp.find(nums[i])!=mp.end() && i-mp[nums[i]] <=k){
            return true;

        }

        mp[nums[i]]=i;

    }
    return false;
}

int main(){
    vector<int>nums ={ 1,3,5,6,77,5,1,2,3,4,4};
    int k=2;
    if(containdup(nums,k)){
        cout<<"there are two equal number at distance less then k"<<endl;

    }
    else{
        cout<<"there exist no such number"<<endl;
    }

    return 0;
}
///////////////////////////////////////////////////////////////////

//Count all the (i,j) Pairs such that b[i] + b[j] == k (count of such pairs.) [i<j] 

//well the approach for problem like this is pretty simple you just have to look for such b[i] that have value equalt to some previous k-b[j]


#include<iostream>
#include<unordered_map>
#include<vector>

int countpairs(vector<int>arr, int k){
    unordered_map<int,int>mp;
    int count=0;
    for(int i=0;i<arr.size();i++){

        if(mp.find(k-ar[i])!=mp.end()){
            count+=mp[k-arr[i]];

        }
        mp[arr[i]]++;
    }
    return count;
}
//////////////////////////////////////////////////////////////
//Count all i,j pairs where i<j and abs(b[i]-b[j]) = k [k>=0]

//similar to the previous problem here alsow we will do the same but while adding the pairs of the k-arr[i] we will also look out for the pairs that are k+arr[i]

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int solve(vector<int>arr, int k){
    int n=arr,size();
    int ans=0;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        if(mp.find(arr[i]-k)!=mp.end()){
            ans+=mp[ar[i]-k];

        }
        if(mp.find(arr[i]+k)!=mp.end()){
            ans+=mp[arr[i]+k];
        }
        mp[arr[i]]++;

    }
    return ans;
}

int main(){
    vector<int>arr={1,2,3,3,5,6,7};
    int k=2;
    cout<<solve(arr,k)<<endl;
    return 0;
}

////////////////////////////////////////////////////////////
 //Find Sum of Range  [l……….r] where(l<=r) using Prefix sum.

 //this is the prefix sum problem so we just sum up the values

 #include<iostream>
 #include<vector>
 using namespace std;

 vecotor<int>prefixsum(vector<int>nums){
    int n=nums.size();
    vector<int>prefix(n+1,0);
    for(int i=1;i<=n;i++){
        prefix[i]= prefix[i-1]+nums[i];
    }
    return prefix;
 }

 int optimize(vector<int>prefix,int l,int r){
    return prefix[r]-prefix[l-1];
 }

 int main(){
    vecotor<int>nums={0,12,3,534,54,64,6,56,57,6,76,7,68,678,7,87,8,7}
    vector<int>prefix=prefixsum(nums);
    int l=2;
    int r=7;
    cout<<"optimzied sum"<<optimize(prefix,l,r)<<endl;

    return 0;
 }


 ///////////////////////////////////////////////////////////////////

 //Find count of number of subarrays with sum ==  k 

 //see the approach is simple firstly you think of solving it of using sliding windown but that is not optimize approach for this question first i was also not able to understand this type of question but what will help you is that 
 //you want to sum that is equal to k then if let say you current sum i x then if you have previously seen the sum x-k then that is your answer just a little crux is that for sum equal to k you have to maintain a sum=0 in map so that whan you encounter a total sum eqaul to k directely you have a anewere for it
 #include<iostream>
 #include<vector>
 #include<unordered_map>
 

 int solve(vector<int>arr,int k){
    int n=nums.size();
    unordered_map<int,int>mp;
    mp[0]=1;


    int sum=0;
    int count=0;
    for(int i=0;i<n;i++){

        sum+=arr[i];
        if(mp.find(sum-k)!=mp.end()){
            count+=mp[sum-k];
        }
        mp[sum]++;


    }
    return count;
 }

 int main(){
    vector<int>arr={1,2,43,5,35,4,64,5,4};
    int k=100;
    cout<<"the sum comes folloing numbere of times"<<solve(arr,k)<<endl;
    return 0;
 }

 ///////////////////////////////////////////////////////////////////


 //Find largest/smallest subarray with sum k in Given Array


// the approach is similar to the above approach but the only thing to keep in mind while problem like this is that you want for largest subarray with sum the trick is to only update the map when you encounter a sum for the first time
//and if for shortest you update the map whenver you encountere the sum

#include<iostream>
#include<unordered_map>
#include<vector>

int solve(vector<int>nums, int k){
    unordered_map<int,int>mp;
    mp[0]=-1;
    int sum=0;
    int maxl=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        if(mp.find(sum-k)!=mp.end()){
            length=i-mp[sum-k];
            maxl=max(maxl,l);

        }
        if(mp.find(sum)==mp.end()){//if encounter the sum for the first time ever
            mp[sum]=i;
        }


    }
    return maxl;
}

int main(){

    vector<int>nums={1,3,43,54,554,65,65,6567,7676,67,68,6};
    int k=1055;
    cout<<solve(nums,k)<<endl;
    return 0;
}

//Find count of shortest/largest subarrays with sum k in given array
//now this is intresting question firstly we find the longest length subarray with sum k then we will make another function that will allow us to count the number of subarrays with that sum

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

pair<int,int>findsubarray(int n,int k,vector<int>arr){
    unordered_map<int,int>mp1;
    unordered_map<int,int>mp2;

    mp[0]=0;

    int  psum=0;
    int maxlength=0;
    int minlength=INT_MAX;

    for(j=1;j<=n;j++){
        psum+=arr[j-1];
        int x=psum-k;
        if(mp1.find(x)!=mp1.end()){
            int i=mp1[x]+1;
            int currlength=j-i+1;
            if(currlength>maxlength){
                maxlength=currlength;
            }

        }
        if(mp2.find(x)!=mp2.end()){
            int i=mp2[x]+1;
            int currlength=j-i+1;
            if(currlength<minlength){
                minlength=currlength;
            }

        }
        if(mp1.find(psum)==mp.end()){
            mp1[sum]=j;
        }

        mp2[psum]=j;


    }
    return {maxlength,minlength};
}
int countsubarray(int n,int k,vector<int>arr,int targetlength){
    if(targetlength==0)return 0;
    int count=0;
    int windowsum=0;
    for(int j=0;j<targetlength;j++){
        windowsum+=arr[j];
    }
    for(int j=targetlength;j<n;j++){
        windowsum+=arr[j]-arr[j-targetlength];
        if(windowsum==k){
            count++;
        }

    }
    return  count;
}

int main() {
    int n = 6;
    int k = 5;
    vector<int> arr = {1, 2, 3, 4, 2, 5};
 
    auto [maxLength, minLength] = findsubarray(n, k, arr);
    int maxCount = countsubarray(n, k, arr, maxLength);
    int minCount = countsubarray(n, k, arr, minLength);
 
    cout << "Max Length: " << maxLength << " Count: " << maxCount << endl;
    cout << "Min Length: " << minLength << " Count: " << minCount << endl;
 
    return 0;
}


//valid anagram
bool isAnagram(string s,string t){

    unordered_map<char,int>count;
    for(auto x:s){
        count[x]++;
    }
    for(auto x:t){
        count[x]--;
    }

    for(auto x:count){
        if(x.second!=0){
            return false;
        }
    }
    return true;
}
