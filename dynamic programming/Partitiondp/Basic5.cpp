/*Find the number of partitions of an array such that each contiguous partition consists of at least one negative number.
eg. [-2,1,-3] has these possible partitions :
-> [-2,1][-3]
-> [-2][1 -3]
->[-2 1 -3] 
*/


#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int>b(n+1);
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }


    vector<int>dp(n+1,0);

    int prev=-1;

    for(int i=0;i<=n;i++){
        if(b[i]>0){
            dp[i]=dp[i-1];

        }

        else{

            if(prev!=-1){
                int d=abs(prev-i)+1;
                dp[i]=dp[i-1]*d;
                prev=i;
            }
            else{

                dp[i]=1;
                prev=i;
            }



        }
    }

    cout<<dp[n]<<endl;
    return 0;
}