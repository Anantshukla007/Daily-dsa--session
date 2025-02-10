/*Just tell true or false; tell true if it is possible to divide the array in a partition such that each part is good. 
*/


#include<iostream>
#include<vector>
using namespace std;

int main(){

    int n;
    cin>>n;


    vector<int>b(n+1);
    for(int i=1;i<=n;i++){
        cin>>b[i];

    }

    vector<bool>dp(n+1,false);

    dp[0]=true;
    for(int i=1;i<=n;i++){
        dp[i]=false;

        for(int j=i;j>=1;j--){
            if(b[j]==i-j){
                if(dp[j-1]==true){
                    dp[i]=ture;
                }
            }
        }
    }

    if(dp[n]){
        cout<<"true case"<<endl;

    }
    else{
        cout<<"false case"<<endl;
    }

    return 0;
}


//follow up

/* Minimum number of moves to make sure your array can be divided into good parts. 

In 1 move you can remove any number ;
*/