/*Find the number of ways to partition array such that each part has a prime number in it 
*/


#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n<2)return false;
    if(n==2||n==3){
        return true;
    }
    if(n%2==0 || n%3==0){
        return false;
    }

    for(int i=5;i*i<=n;i+=6){
        if(n%i==0 || n%(i+2)==0)return false;


    }
    return true;
}


int main(){

    string s;
    cin>>s;
    int n=.size();
    vector<int>dp(n+1,0);

    dp[0]=1;//one way to form an empty sequence

    for(int i=0;i<n;i++){
        string u="";
        for(int j=i;j>max(0,i-6);j--){
            u=s[j]+u;
            if(u[0]!='0'){
                int num=stoi(u);
                if(isPrime(num)){
                    dp[i+1]+=dp[j];
                }
            }
        }
    }

    cout<<dp[n]<<"\n";
    return 0;
}