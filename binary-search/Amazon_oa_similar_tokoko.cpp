/*You are given an array of size “N” ; you are given a capacity of “k” ; 
Each element can be reduced by at most k in 1 move. You are allowed to make maximum “d” moves. Find the minimum possible value of “k” 
*/


#include<btis/stdc++.h>
using namespace std;

bool check(int k, vector<int>b, int d){

    int n=b.size();

    int sum_moves=0;

    for(int i=0;i<n;i++){

        if(b[i]%k==0){
            sum_moves+= b[i]/k;
        }
        else{
            sum_moves+=(b][i]/k)+1;
        }
    }
    return sum_moves<=d;
}


int main(){
    int n,d;

    cin>>n>>d;

    if(d<n){
        cout<<-1<<endl;
        return 0;

    }

    vector<int>b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    int limit=*max_element(b.begin(),b.end());
    int low=1;
    int high=limit;
    int u=0;
    int answer=0;

    while(low<=high && u==0){
        int mid=(low+high)/2;
        if(check(mid,b,d)==false){
            low=mid+1;
        }

        else{
            if(mid==1){
                u=1;
                answer=mid;
                
            }
            else if(check(mid-1,b,d)==false){
                u=1;
                answer=mid;
            }
            else{
                high=mid-1
            }
        }
    }

    cout<<answer<<endl;
    return 0;
}