/*We are given “n” type of items ; array b is given which tells us -> b[i] = frequency of item “i” ; 

Our task is to make a group of k distinct items; 

And finally output how many maximum such types of groups can be formed. 


-> [3 3 3] ; K = 2 

Output :- 4 
*/

/*now what i always belive is that check  funcition plays the main role in the binary search
any body can write the binary search but check that is what matters now in this question also you need to make maximum groups and
each group must have k distinct items how many groups can be that we dont know lets sya thery are infinity then we can search till infinity we need to seacrh until we can find a position in infinity that can have k distinct element in group
and even increasing a single group will turn false

some thing like {ttttttttttttttttttttttttttt[t]fffffffffffffffffffffffffffffffff} the t inide the brackec is our answer*/

#include<bits/stdc++.h>
using namespace std;

vector<int>b;
int n,k;
bool check(int g){
    int t=g*k;//if there are g  groups and k distinct elements in each s we need t elements to satisty the need
    int i=1;
    while(i<=n){
        if(b[i]>g){
            t=t-g;
        }
        else{
            t=t-b[i];

        }
    }
    if(t<=0){
        return true;
    }
    return false;

}


int main(){
    cin>>n;
    cin>>K;
    b.resize(n);
    int sum=0;
    int i=1;
    while(i<=n){
        cin>>b[i];
        sum+=b[i];
        i++;
    }
    int ans=0;
    int low=1;
    int high=1e18;
    int y=0;

    while(low<=high && y=0){
        int mid=(low+high)/2;

        if(check(mid)==true && check(mid+1)==false){
            ans=mid;
            y=1;

        }

        else if(check(mid)==true){
            low=mid;;
        }

        else{
            high=mid-1;

        }
        
    }

    cout<<ans;
    return 0;
}