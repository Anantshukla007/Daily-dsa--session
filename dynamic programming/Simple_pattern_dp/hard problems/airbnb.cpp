/*There are 'n' stones in a row from 0 to n-1. For every ith stone , there are 2 values associated with it, a[i] and b[i] . You have to remove all the stones from the row one by one. Removing the ith stone follows the rule :

 

 

If (i-1)th and (i+1)th stones are still present , then , cost of removing the ith stone is b[i].

 

 

if either (i-1)th or (i+1)th stone is present , then cost of removing the ith stone is a[i].

 

 

if neither (i-1)th nor (i+1)th stone is present , the cost of removing the ith stone is 0.*/



//the issue with this problem is that you not only have to work with the forward stone
/*but also with any backward stone and how we order the picking of these stone like what stone i pick when i pick so little complex


okay lets work it out let us first two pciking state that would be
first->either you pick the last stone in such a way that it is the second last stone to be picked ie:-what ever order the
may be before i will make sure that the element at index i shall be second last to be picked

so this will look like a[i]+dp[i-1][?] state

i have used ? because i have yet not come up with all the states

but the second state could be of picking the element at i index is picked last 

so if i pick this as last we will have 0 cost for it but in aht order were the previous element picked

but till now there are two states that i have fixed 

last and second last

dp[i][1]=last
dp[i][2]=second last 

but now what now lets workout with these states and the previous conclusion we worked so far with


so for the first case that we pick the last element as seconde last now will have solution like this

dp[i][1]=a[i]+min(dp[i-1][1],dp[i-1][2])//the previous element could have been picked in any order just like this element right 


now case where the element is picked last

case 1 -> when the index i element  i picked as last it makes the case where it exist with the i-1 element 

it will look like i-2, i-1, i
now when i is picked as last either you  pick i-1 first right such that i-2 also exited so

it will be 
b[i-1]+min(dp[i-2][1],dp[i-2][2]); now the last cost is 0 i-1 cost is b[i-1] and for the i-2 we dont know what we did there we use the best previous stat

now what if i picke i-1 element such that only i index element existed it means i will cost us 0 i-1 will cost a[i-1] but what about the previous elements
but if look closely we will realize that this i-1 is just the second last pick and exhausted all the previous element by picking them so in the end we will be holding the 
answer in dp[i-1][2] 

so now lets code it

*/


#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int b[n+1],a[n+1];

    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }


    int dp[n+1][3];

    dp[2][1]=a[2];
    dp[2][2]=a[1];
    dp[1][1]=0;
    dp[1][2]=0;

    for(int i=3;i<=n;i++){
        dp[i][1]=a[i]+min(dp[i-1][1],dp[i-1][2]);

        int v1=b[i-1]+min(dp[i-2][1],dp[i-2][2]);

        int v2=a[i-1]+dp[i-1][2];

        dp[i][2]=min(v1,v2);
    }


    cout<<min(dp[n][1],dp[n][2])<<endl;

    return 0;
}

