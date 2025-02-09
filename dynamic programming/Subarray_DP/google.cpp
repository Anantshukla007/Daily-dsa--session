/*Given a string please tell how many substring pairs are in the palindrome. 

[l1……..r1] and [l2…….r2] are valid pairs if l1<=r1 < l2<=r2 and [l1….r1] = palindrome. [l2…….r2] = palindrome. 

-> bbaa :- 10 valid pairs. 



*/

//now this problem is a slight differnt take on the problem that we have solved so far here we have to form two subarrays and they can be at any psoition lets dicuss it


/*now the question is aksing us to make pairs but the main point is where to start making pairs if normal subarray problem 
would have been there it could have been easily solved but here we
are stuck on division of the array 

ok now the main idea of the divison can handeled by adding a stick the stick can be placed anywhere in the array and total count of palindrmic subarrays before it shall be multiplied by the pairs after it
right simple but if fix the stick the question is that sahll i take all pairs
before the index i or only those pairs that end at index i 
now this is a important question becuse if continously take all pairs before i whether they end at i or not then 
you are going to reccount the pairs which will cause error to avoid this 
you shall count only those pair that end at index i */


/*now the intresint part is that google asked not to find pairs but triplets
so it was necessary to talk about the pairs first then triplets 

because the logic for triplet is pretty simple now when ever you insert a stick you will already know number of pairs after that index and and number of palindromic substrings ending there 
then answer can be easily calculated but this make the code very lengthy*/


#include<bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin>>s;

    int n=s.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    vector<vector<int>>dpc(n,vector<int>(n,0));

    //length 1;

    for(int i=0;i<n;i++){
        dp[i][i]=1;
        dpc[i][i]=1;
    }

    //length 2

    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            dp[i][i+1]=1;
            dpc[i][i+1]=3;
        }
        else{
            dpc[i][i+1]=2;
        }
    }

    //length 3

    for(int len=3;len<=n;len++){
        for(int i=0;i<n-len+1;i++){
            int j=i+len-1;

            if(s[i]==s[j] && dp[i+1][j-1]==1){
                dp[i][j]=1;
            }

            dpc=dpc[i+1][j]+dpc[i][j-1]-dpc[i+1][j-1]+dp[i][j];
        }
    }


    //now working on palindromic pairs

    vector<int>pdpp(n,0);
    for(int i=0;i<n;i++){
        int j=i;
        int b=0;

        while(j>=0){
            if(dp[i][j]==1){
                b++;
            }
            j--;
        }

        if(i+1<n){
            int rest=dpc[i+1][n-1];
            int val=b*rest;
            pdpp[i]=val;
        }
    }

    //now lets make triplets

    vector<int>pdpt(n,0);
    for(int i=0;i<n;i++){
        int j=i;
        int b=0;
        while(j>=0){
            if(dp[j][i]==1){
                b++;
            }

            j--;
        }

        if(i+1<n){
            int rest=0;
            for(int k=i+1;k<n;k++)
            {
                rest+pdpp[k];
            }

            int val=b*rest;
            pdpt[i]=val;
        }
    }

    int total=0;
    for(int i=0;i<n;i++){
        total+=pdpt[i];
    }
    cout<<total<<endl;
}