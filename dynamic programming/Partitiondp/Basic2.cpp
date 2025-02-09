/*-> Given an array of size ‘N’; find the number of ways to partition it such that the sum of each part is <=M ; but you should only make k partitions!
*/

/*now this is just a simple follow up */

#include<bits/stdc++.h>
using namespace std;


int dp[105][105];

int main(){

    int n;
    cin>>n;
    int m;
    cin>>m;
    int b[n+1]={0};
    for(int i=1;i<=n;i++){
        cin>>b[i];
        
    }

    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            dp[i][j]=-1e8;

        }
    }

    dp[0][0]=1;
    dp[1][1]=1;

    for(int i=2;i<=n;i++){
        int prt=1;

        while(prt<=k){
            int v=0;
            int j=i;
            int sum=b[i];
            while(j>=1 && sum<=m){
                int g=d[j-1][prt-1];
                if(g>0){
                    v=v+g;

                }
                j--;
                sum=sum+b[j];
            }
            if(v>0){
                dp[i][prt]=v;
            }

            prt++;
        }

    }
    cout<<dp[n][k];
    return 0;

    
}