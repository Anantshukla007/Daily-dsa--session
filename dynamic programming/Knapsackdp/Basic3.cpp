/* We are given “N” rows. Each row has “M” elements; we have to select 1 element from each row. 

Once we are done with it final sum of all elements should be as close as possible to K 

Analysis :-> 

N = 5 
M = 2
K = 40 
{
3 5
5 8 
8 8 
10 10
11 15
}

Output :-> Abs(sum-K) = (40-40) = 0 
*/

#include<bits.stdc++.h>
using namespace std;

int main(){
    int n,m,k;

    cin>>n>>m>>k;

    vector<vector<int>>b(n+1,vector<int>(m+1));
    vector<vector<int>l(n+1,vector<bool>(50001,false));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>b[i][j];
        }
    }

    l[0][0]=true;

    for(int i=1;i<=n;i++){
        for(int sum=1;sum<=5000;sum++){
            for(int j=1;j<=m;j++){

                int y1=b[i][j];
                int p=sum-y1;
                if(p>=0 && l[i-1][p]){
                    l[i][sum]=true;
                }
            }
        }
    }

    int y=10000;
    for(int i=1;i<=5000;i++){
        if(l[n][i]){
            int po=abs(i-l);
            u=min(y,po);
        }
    }
    cout<<y<<endl;

    return 0;
}