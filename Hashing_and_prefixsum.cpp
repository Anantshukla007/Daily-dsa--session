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


//Understanding :-> You are given an array “A”; in one step select largest element of array and convert it to second largest element of the array 

#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>b(n+1);
    map<int,int>mp;

    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        mp[b[i]]++;
    }

    vector<pair<int,int>>g;
    for(auto u:mp){
        g.push_back({u.first,u.second})
    }
    int size=g.size();
    int step=0;

    for(int i=size-1;i>=1;i--){
        g[i-1].second+=g[i].second;
        step+=g[i].second;
        g[i].second=0;
    }
    cout<<step<<endl;
    return 0;


}

//Frist unique charecter in a string

int firstuniqueschar(string s){
    unordered_map<char,int>hm;
    for(char c:s){
        hm[c]++;
    }
    for(int i=0;i<n;i++){
        if(hm[s[i]]==1){
            return i;
        }
    }
    return -1;
}

int main(){
    string s="leetcode";
    cout<<firstuniqueschar(s)<<endl;
    return 0;
}

//find commmon charecters


vector<string>commmonchars(vector<string>words){
    vector<string>results;
    if(words.empty())return results;

    vector<int>minfreq(26,INT_MAX);
    for(const auto word:words){
        vector<int>freq(26,0);
        for(char c:word){
            freq[c-'a']++;
        }
        for(int i=0;i<26;i++){
            minfreq[i]=min(minfreq[i],freq[i]);

        }
    }
    for(int i=0;i<26;i++){
        while(minfreq[i]>0){
            result.push_back(string(1,i+'a'));
            minfreq[i]--;
        }
    }
    return result;
}



//longest consicutive sequence

int longestConsecutinve(vector<int>nums){
    int n=nums.size();
    unorderd_map<int,int>mp;
    int ans=0;
    for(int i=0;i<n;i++){
        if(mp[nums[i]]==0){
            mp[nums[i]]++;
        }
    }

    for(int i=0;i<n;i++){
        int val=nums[i];
        if(mp.find(val)!=mp.end() && mp.find(val-1)==mp.end()){
            int curr=val;
            cnt=0;
            while(mp.find(curr)!=mp.end()){
                mp[curr]--;
                cnt++;
                curr++;
            }
            ans=max(ans,cnt);
        } 
        return ans;
    }
}

//longest subarray sum with 0 sum

#include<unordered_map>
#include<algorithm>
using namespace std;
int solve(vector<int>A, int n){
    int sum=0;
    int longest_length=0;
    unordered_map<int,int>mp;
    mp[0]=--1;
    for(int i=0;i<a.size();i++){
        sum+=a[i];
        if(mp.find(sum)!=mp.end()){
            longest_length=max(longest_length,i-mp[sum]);
            
        }
        else{
            mp[sum]=i;
        }
    }
    return longest_length;

}

int main(){
    vector<int>a={193,5,546,567,57,67,67,67,6};
    int answer=solve(a,n);
    cout<<"answer is"<<answer<<endl;
    return 0;
}

//count number of pairs with absolute differnce k

int countkdiff(vector<int>num,int k){
    unorderd_map<int,int>mp;
    int count =0;

    for(int i=0;i<n;i++){
        if(mp.find(nums[i]-k)!=mp.end()){
            count+=mp[nums[i]-k]

        }

        if(mp.find([nums[i]]+k)!=mp.end()){
            count+=mp[nums[i]+k];
        }
        mp[nums[i]]++;
    }
    return count;
}


//find the prefix common arrays

#include<bits/stdc++.h>
using namespace std;

#define ll long long


int main(){

    ll n;
    cin>>n;

    vector<ll>A(n,0),B(n,0);

    for(int i=0;i<;i++){
        cin>>A[i];
    }

    for(int i=0;i<n;i++){
        cin>>B[i];
    }

    vector<ll>ans;
    int i=1;
    if(A[0]==B[0]){
        ans.push_back(1);
    }
    else{
        ans.push_back(0);
    }

    while(i<A.size()){
        unordered_map<int,int>mp;
        for(int j=i;j>=0;j--){
            mp[A[j]]++;
        }

        int cnt=0;
        for(int j=i;j>=0;j--){
            if(mp.find(B[j])!=mp.end()){
                cnt++;
                mp[B[j]]--;
                if(mp[B[j]]==0){
                    mp.erase(B[j]);
                }
            }
        }
        ans.push_back(cnt);
        i++;
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";

    }
    return 0;
}


//longest palindrome byb concatenating two letters words

int longestpalindrome(vector<string>words){
    int len=0;
    int count =0;
    int flag=0;

    unorderd_map<string,int>mp;

    for(int i=0;i<n;i++){
        mp[words[i]]++;
    }

    for(int i=0;i<words.size();i++){
        if(words[i][0]!= words[i][1]){
            string s=" ";
            s+=words[i][1];
            s+=words[i][0];

            if(mp.find()!=mp.end()){
                count=min(mp[words[i]],mp[s]);
                len+=count*4;
            }

            mp.erase(words[i]);
            mp.erase(s);
        }

        else if(words[i][0]==words[i][1]){
            count=mp[words[i]];
            if(mp[words[i]]%2==0){

                len+=count*2;
            }
            else{
                if(flag==0){
                    len+=count*2;
                    flag=1;
                }
                else{
                    len+=(count-1)*2;
                }
            }
        }
        mp.erase(words[i]);
    }
    return len;
}

//Understanding - We are given an array of size N ; we are told to pick up any 2 numbers from the array such that their digit sum is equal ; if their digit sum is equal ; calculate their sum ; question is saying to find the maximum possible sum 


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll sol(ll v){
    ll sum=0;
    while(v!=0){
        sum=sum+v%10;
        v=v/10;


    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    ll b[n+1]={0};

    ll i=1;

    while(i<=n){
        cin>>b[i];
        i++;
    }

    unorderd_map<ll,ll>kk;

    int i=1;
    ll answer=-1;
    while(i<=n){

        if(kk.find(sol(b[i])!==kk.end())){
            ll pp=b[i]+kk[sol(b[i])];

            answer=max(answer,pp);
            kk[sol(b[i])]=max(kk[sol(b[i])],b[i]);
        }
        else{
            kk[sol(b[i])]=b[i];
        }
        i++;
    }
    cout<<answer;
    return 0;
}


//Find cnt of string t in string s until we are getting string t in string s; if any char of t doesn’t present in s at any moment then we will break & return the cnt; & if string s is empty at any moment then again we will break from the loop & return the cnt. 


#include<bits/stdc++.h>
using namespace std;
int main(){

    string s,t;

    cin>>s>>t;

    unordered_map<char,int>mp1,mp2;

    for(int i=0;i<s.size();i++)mp1[s[i]]++;
    for(int i=0;i<t.size();i++)mp2[t[i]]++;

    int cnt=1e9;

    for(int i=0;i<t.size();i++){
        if(mp1.find(t[i])==mp1.end()){
            return 0;
        }

        int val=mpq[t[i]]/mp2[s[i]];

        cnt=min(cnt,val);
    }

    cout<<cnt;
    return 0;

}

//We are only solving the easy version of this problem in this session. 

//1<=a[i]<=100000
//1<=k<=100000

//a[i]-k>=1 and a[i]+k<=100000 

//—------------------------------------------------------------------

//Harder version -> 

//1<=a[i]<=10000000000
//1<=k<=10000000000


//For the harder version you need to watch this video + document complete then you will get how to solve the harder version of the above problem. 


//this is called the range sum query question 

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>;
    int a[n+1];
    int k;
    cin>>k;

    int i=1;

    while(i<=n){
        cin>>a[i];
        i++;
    }

    int b[200006]={0};

    i=1;
    while(i<=n){
        int l=a[i]-k;
        int r=a[i]+k;
        b[l]=b[l]+1;
        b[r+1]=b[r+1]-1;
        i=i+1;
    }
    int answer=1;
    i=1;
    while(i<20006){
        b[i]=b[i-1]+b[i];
        answer=max(b[i],answer);
        i++;
    }
}
cout<<answer;
return 0;



//
/*P0 : You are given an array of size “N”; all elements are 0 in it :) 
You are given Q queries :-> [L,R] ; you have to add +1 to all the elements from [L,R] 

-> After all queries are performed you have to print the final answer 
*/

#include<iostream>
using namespace std;

int main(){
    int n,Q,p;
    cin>>n>>Q>>p;

    int b[100001]={0};

    for(int i=1;i<=Q;i++){

        int L,R;

        cin>>L>>R;

        b[L]=b[L]+1;

        if(R+1<=n){
            b[R+1]=b[R+1]-1;
        }
    }

    for(int i=1;i<=n;i++){
        b[i]=b[i]+b[i-1];

    }


    for(int i=1;i<=p;i++){
        int y;
        cin>>y;
        cout<<b[y]<<endl;
    }

    return 0;
}



/*


> You are given an array of size “N” and two integers “x” and “y” 
-> Array only consists of integers “x” and “y”
-> Find the count of subarrays which have equal number of “x” and “y” 

*/

//when in any particular range lets say i to j then countofx[j]-countofx[i-1] will be equal to countofy[j]-countofy[i-1]
// so this is a simple trick to solve this type of problems 


#include<iostream>
#include<vector>
#include<unorderd_map>

using namespace std;

int main(){
    int n,x,y;

    cin>>n>>x>>y;

    for(int i=1;i<=n;i++){
        cin>>b[i];
    }

    long long count =0;
    unordered_map<int,int>mp;

    mp[0]=1;

    int cx=0;
    int cy=0;

    for(int i=1;i<=n;i++){
        if(b[i]==x){
            cx++;
        }
        else{
            cy++;
        }
        int d=cx-cy;
        count+=mp[d];
        mp[d]++;


    }

    cout<<count<<endl;
    return 0;
}


//follow up what if we had three numbers x ,y and z;

// the logic would remain same but we will need to check not two but three differnces to coexist in a range


#include<bits/stdc++.h>
using namesapce std;

int main(){

    int n,x,y,z;

    cin>>n>>x>>y>>z;

    vector<int>b(n+1);

    for(int i=1;i<=n;i++){
        cin>>b[i];

    }


    long long count =0;

    map<pair<int,int>,int>mp;
    mp[{0,0}]=1;

    int cx=0;
    int cy=0;
    int cz=0;


    for(int i=1;i<=n;i++){

        if(b[i]==x){
            cx++;
        }
        else if(b[i]==y){
            cy++;
        }
        else{
            cz++;
        }

        int d1=cy-cx;
        int d2=cz-cy;

        count+=mp[{d1,d2}];

        mp[{d1,d2}]++;
    }
    cout<<count<<endl;
    return 0;
}


//now the same question but wiht four numbers


#include<bits/stdc++.h>
using namespace std;

int solution(int n,int x,int y,int z,int w,int b){
    int count =0;

    map<tuple<int,int,int ,int>>mp;

    mp[{0,0,0,0}]=1;

    int cx=0;
    int cy=0;
    int cw=0;
    int cb=0;
    int cz=0;

    for(int i=0;i<n;i++){


        int val;
        cin>>val;

        if(val==x){
            cx++;
        }
        else if(val==y){
            cy++;
        }
        else if(val==z){
            cz++;
        }
        else if(val==w){
            cw++;
        }
        else{
            cb++;
        }


        int d1=cy-cx;
        int d2=cz-cy;
        int d3= cw-cz;
        int d4= cb-cw;

        count+= mp[{d1,d2,d3,d4}];

        mp[{d1,d2,d3,d4}];



    }

    return count;
}

/*Implement a simple meeting assistant. A list of strings, events[n], in the form "<person_name> <action> <start> <end>" is provided
where person_name performs action from start to end, both inclusive. Times are formatted HH:MM. Find the earliest time in the day, from "00:00" to "23:59", when all people mentioned in at least one event are available for a meeting of k minutes. Report the answer as "HH:MM" or the string "-1" if it is not possible.*/


/* the first thing about this question is that we need to conver the HH:MM totla minute  */


#include<bits.stdc++.h>
using namespace std;


//converting then hh:MM format to total minutes
int convert(string s){
    int u1=int(s[0])-48;
    int u2=int (s[1])-48;

    int v=(u1*10+u5)*60;

    u1=int(s[3])-48;
    u5=int(s[4])-48;

    v=v+(u1*10+u5)

    return v;


}


void ck(int g){
    int u=g/60;
    int y=g%60;

    if(u<=9){
        cout<<"0";
        cout<<u;
    }

    else{
        cout<<u;
    }

    cout<<":";

    if(y<=9){
        cout<<"0";
        cout<<y;
    }
    else{
        cout<<y;

    }

    int main(){
        int n;

        cin>>n;

        int k;
        cin>>k;

        int y[10000]={0};

        for(int i=0;i<n;i++){

            string a,b,v1,v5;

            cin>>a;
            cin>>b;
            cin>>v1>>v5;

            int t1=convert(v1);
            int t5=convert(v5);

            y[t1]++;
            y[t5+1]--;
        }
        int i=1;

        while(i<10000){
            y[i]=y[i]+y[i-1];
            i++;
        }

        int c=0;int g=0;

        for(int i=0;i<10000;i++){

            if(y[i]==0){
                c++;
            }
            if(c==k){
                ck(i-k+1);
                g=1;
                break;
            }


        }
        else{
            c=0;
        }
    }
    if(g==0){
        cout<<"-1";
    }
}



/*

Q. Find the count. of subarray of shortest length whose sum==k
A = {10,5,2,7,1,9,8,7}   k = 15


*/

#include<bits/stdc++.h>
using namesapce std;

void subarray_problem(vector<int>arr,int k){

    int mini=1e9;

    int sum=0;
    unorderd_map<int,int>mp;

    mp[0]=-1;

    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(mp.find(sum-k)!=mp.end()){
            mini=min(mini,i-mp[sum-k]);

        }

        mp[sum]=i;
    }

    if(mini !=1e9){
        int i=0;
        int cnt=0;
        int s=0;
        int k1=mini;
        while(j<arr.size()){
            s+=arr[j];
            if(j-i+1<k1){
                j++;
            }

            else if(j-i+1==k1){
                if(s==k){
                    cnt++;
                }
                s-=arr[i];
                i++;
                j++;
            }
        }
        cout<<cnt;

    }


}

int main(){
    vector<int>arr={5,46,465,65,65,6};
    int k=5;
    subarray_problem(arr,k);
    return 0;
}


/*Task given in problem is to Find Number of Pairs in array A, i and j such that A[A[A[i]]] == A[A[A[j]]]

*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n+1];
    int i=1;
    while(i<=n){
        cin>>a[i];
        i++;
    }

    unorderd_map<int,int>mp;

    int count=0;
    i=1;

    while(i<=n){
        int rhs=a[a[a[i]]];
        int g=mp[rhs];

        count=count+g;
        int lhs=a[a[a[i]]];

        mp[lhs]=mp[lhs]+1;
        i++;
    }

    cout<<count;
    return 0;
}



/*Maximum Sum Selection

You are given an integer array A of size N. Your task is to select exactly B elements from either the left end or the right end of the array A in order to maximize the sum of the selected elements.

Here are the details of the problem:

You are given an integer array A of size N where 1 <= N <= 10^5.
You need to select exactly B elements from either the left end or the right end of the array A.
The goal is to find and return the maximum possible sum of elements you can pick.

Input:

An integer array A of size N where each element A[i] satisfies -103 <= A[i] <= 103.
An integer B where 1 <= B <= N.
Output:

An integer representing the maximum possible sum of selected elements.

[5, -2, 3, 1, 2], 3 -> 8*/



#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>a,int b){

    int n=a.size();
    int suff[n+1];

    suff[n]=0;
    suff[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        suff[i]=suff[i+1]+a[i];

    }

    int presum=0;
    int ans=suff[n-b];

    for(int i=0;i<b;i++){
        presum=presum+a[i];
        int suffsum=suff[n-b+(i+1)];
        ans=max(ans,presum+suffsum);
    }

    return ans;
}

int main()
{
	vector<int>A={5, -2, 3,1,2};
	int B=3;
	cout<<solve(A,B);
	return 0;
}

/*-> You are given string a and string b ; you have to output Yes ; if both of the strings can be made equal by doing some specific operations. 

What are those operations?

-> You can swap any even index element with any other even index element of same string 
*/


bool check(string x,string y){
    int i=0;

    unorderd_map<char,int>mp1,mp2,mp3,mp4;

    while(i<x.size()){
        char g=x[i];

        if(i%2==0){
            mp1[g]++;
        }
        else{
            mp2[g]++;
        }
        i++;

    }
    i=0;

    while(i<y.size()){
        char g=y[i];

        if(i%2==0){
            mp3[i]++;
        }
        else{
            mp4[g]++;
        }
        i++;
    }

    if(mp1==mp3 && mp2== mp4){
        return true;
    }
    return false;
    
}

/*Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0*/



int solve(vector<int>nums1,vector<int>numd2;vector<int>nums3,vector<int>nums4){

    map<int,int>mp;

    for(int k:nums3){
        for(int l:nums4){
            mp[k+l]++;
        }


    }

    int count=0;

    for(int i:nums1){
        for(int j:nums2){
            count+=mp[-(i+j)];
            
        }
    }

    return count;
}


/*Problem.-> Given an array of size “N”; find the number of triplets; such that A[i] >A[j]< A[k] such that i < j < k ; 
*/


#include<bits/stdc++.h>
using namsepace std;
int main(){
    int n;
    cin>>n;

    int b[n+1];

    int pre[n+1]={0};

    int suf[n+1]={0};

    pre[1]=0;

    for(int i=1;i<=n;i++){
        cin>>b[i];
    }

    int j=2;
    while(j<=n){

        int c=0;

        int i=1;
        while(i<=j-1){
            if(b[i]>b[j]){
                c++;
            }
            i++;



        }

        pre[j]=t;
        j++;


    }

    suff[n]=0;




    int k=n-1;
    while(k>=1){

        int c=0;
        int l=k+1;
        while(l<=n){
            if(b[k]>b[l]){
                c++;
            }
            l++;
        }
        suff[k]=c;
        k--;
    }

    int c=0;

    int j=1;

    while(j<=n){
        int k=j+1;

        while(k<=n){
            if(b[j]<b[k]){
                c=c+pre[j]*suf[k];
            }

            k++;
        }
        j++;
    }
    cout<<c;
    return 0;
    
}



/*
Given 5 arrays :- A,B,C,D,E  all of size “N” 

Element in the array can range from [-10^9……….10^9]

Find the number of tuplets (i,j,k,l,m) such that  - 

a[i] + b[j] + c[k] + d[l] + e[m] = 0

A = [2 5]
B = [3 8]
C = [-5 8]
D = [5 10]
E = [-10 100] 

Output - 1 (2,5,-5,10,-10) 



*/


#inlcude<iostream>
#include<unorderd_map>

using namespace std;

int main(){


    int n=2;
    int a[] = {2, 5};
    int b[] = {3, 8};
    int c[] = {-5, 8};
    int d[] = {5, 10};
    int e[] = {-10, 100};

    unorderd_map<int,int>mp;

    for(int i=0;i<n;i++){
        for(j=0;j<n;j++){
            int sum=d[l]+e[m];
            mp[sum]++;
        }
    }

    int count=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                int reduced_sum=-(a[i]+b[j]+c[k]);
                count+=mp[reduced_sum];
            }
        }
    }

    cout<<count<<endl;
}


/*Input:
N = 3
X = {"abc", "ade", "bbc"}
Output: [3, 0, 0]
Explanation:
For String "abc"(i 1), the subsequent strings are "ade" and "bbc". The matching characters of "abc" with "ade" is 1 which is 'a' at index 1 and the matching characters of "abc" with. "bbc" is 2 which are 'b' and 'c' at index 2 and 3. The answer for "abc" is 1+2=3
For String "ade" (i = 2). the subsequent string is "bbc". The matching characters of "ade" with "bbc' is 0. The answer for "ade" is 0.
For String "bbc"(i answer for "bbc" is 0. 3), there are no subsequent strings. The
We can note that the answer for the last string in the input array will always be 0 as there are no subsequent strings.*/

#include<iostream>
#include<vector>
#include<string>

vector<int>matching(int n, vector<string>x){
    vector<vector<int>>g(20000+5,vector<int>(28,0));

    vector<int>p(n,0);


    for(int i=n-1;i>=0;i--){
        string u=x[i];

        int c=0;
        int d=u.size();
        for(int j=0;j<d;j++){
            int y=int(u[j])-97;

            c=c+g[j][y];
        }

        p[i]=c;
    }

    return p;
}

