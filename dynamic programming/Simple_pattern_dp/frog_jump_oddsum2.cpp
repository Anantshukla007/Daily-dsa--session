/*You are given two arrays a and b -> both are of size “N”. 

Start your journey at index 1 and end your journey at index “N”. 

In a move you can move from a[i]->a[i+1] or a[i]->b[i+1] 

OR 

b[i]->b[i+1] or b[i]->a[i+1]

Output the number of journeys whose sum is even and odd. 



Input -> 

A        B
1         3
2         1
1         1

Total 4 even journeys :- (1→2→1) 2 times; + (3→2→1) 2 times; = 4.
*/

//now if you have solved the previous one this one is just one extra state because we are using two arrays nothing more



#include<iostream>
#include<vector>

using namespace std;

void countjourney(vector<int>a,vector<int>b){
    int n=a.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(2,0)));


    if(b[1]%2==0){
        dp[1][1][0]=1;
        dp[1][1][1]=0;
    }
    else{
        dp[1][1][0]=0;
        dp[1][1][1]=1;

    }
    if(a[1]%2==0){
        dp[1][0][0]=1;
        dp[1][0][1]=0;
    }
    else{
        dp[1][0][0]=0;
        dp[1][0][1]=1;
    }


    for(int i=2;i<=n;i++){
        if(a[i]%2==0){
            dp[i][0][0]=(dp[i-1][0][0]+dp[i-1][1][0]);   
        }
        else{
            dp[i][0][0]=(dp[i-1][0][1]+dp[i-1][1][1]);
        }
                // Update dp[i][a][odd]
        if(a[i] % 2 == 0) {
            dp[i][0][1] = (dp[i - 1][0][1] + dp[i - 1][1][1])  ;
        } else {
            dp[i][0][1] = (dp[i - 1][0][0] + dp[i - 1][1][0])  ;
        }
        
        // Update dp[i][b][even]
        if (b[i] % 2 == 0) {
            dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][1][0])  ;
        } else {
            dp[i][1][0] = (dp[i - 1][0][1] + dp[i - 1][1][1])  ;
        }
        
        // Update dp[i][b][odd]
        if (b[i] % 2 == 0) {
            dp[i][1][1] = (dp[i - 1][0][1] + dp[i - 1][1][1])  ;
        } else {
            dp[i][1][1] = (dp[i - 1][0][0] + dp[i - 1][1][0])  ;
        }
    }
    int evenJourneys = (dp[n][0][0] + dp[n][1][0]) ;
    int oddJourneys = (dp[n][0][1] + dp[n][1][1])  ;
    
    cout << "Even journey count is " << evenJourneys << endl;
    cout << "Odd journey count is " << oddJourneys << endl;
}
