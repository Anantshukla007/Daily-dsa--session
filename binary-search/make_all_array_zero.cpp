/*-> Question is saying to us :- We are given an array and integer k ; we have to make maximum k moves on the array such that all elements of array become <=0 ; also -> in each move you can :-> 

Decrease any number of the array by x . 

K = 15 
*/


/*you want to use maximum k moves and decrese all array elements to zero in each move i can decrease a number by x
so if there were infinite moves the answer would have been always true and was easy but
now what i will do is that there will be no issue now think
another point the best x is definetly the mximum element of array and it will take minimum moves to reduce the whole array to 0
but here we dont want the minimum moves we have a fixed set of moves we want minimum x even then the range wont go out of 1 to the max of the array so just binary search over this range for answer and you will be done */

//  F F F F F F F F F F F T T T T T T T T T T T T T T T T T T T T always try to visualize like this


#include<bits/stdc++.h>
using namespace std;

bool f(int x, int k, int b[], int n){
    int i=1;
    int g=0;
    while(i<=n){
        if(b[i]%x==0){
            g=g+(b[i]/x);
        }
        else{
            g=g+(b[i]/x)+1;
        }
        i++;
    }

    if(g<=k){
        return true;
    }
    return false;
}


int main(){
    int n;
    cin>>n;
    int b[n+1]={0};
    int i=1;
    int sum=0;

    while(i<=n){
        cin>>b[i];
        sum=max(sum,b[i]);
        i++;
    }
    int k;
    cin>>k;

}

int main(){
    int n;
    cin>>n;

    int b[n+1]={0};
    int i=1;
    int sum=0;
    while(i<=n){
        cin>>b[i];
        sum=max(sum,b[i]);
        i++;
    }

    int k;
    cin>>k;
    int low=1;
    int high=sum;
    int kk=0;
    while(low<=high && kk==0){
        int mid=(low+high)/2;

        if(f(mid,k,b,n)==ture){
            if(mid==1){
                answer=1;
                kk=1;
            }
            else{
                if(f(mid-1,k,b,n)==false){
                    answer=mid;
                    kk=1;

                }
                else{
                    high=mid-1;
                }
            }
        }
        else{
            low=mid+1;
        }
    }
    cout<<answer;
    return 0;
}