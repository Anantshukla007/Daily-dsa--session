/*Given a string of integers; divide them ; in such a manner that ; all the parts of that string <=K ; find the number of ways to do it 

S = “123” ; K<=1000

Output :- 4. 

S = “125” ; K = 24 
Output :- 2. 

S = “1234” ; K = 1000
*/


#include<bits/stdc++.h>
using namesapce std;

int main(){
    int n;
    int k;
    cin>>n>>k;
    string s;
    cin>>s;

    int dp[n+1]={0};
    int b[n+1]={0};

    int i=0;
    while(i<=n-1){

        char g=s[i];

        b[i+1]=int(g);
        i++;
    }

    dp[0]=1;
    i=1;
    while(i<=n){
        int j=i-1;

        while(j>=10 && j>=0){
            int l=abs(i-j);
            string vv=.substr(j,l);

            int g=stoi(vv);

            if(g<=k && b[j+1]!=0){
                dp[i]=(dp[i]+dp[j])%md;
            }
            else{

                dp[i]=dp[i]+0;
            }

            j=j-1;
        }
        i++;
    }
    cout<<dp[n]%md;
    return 0;
}
