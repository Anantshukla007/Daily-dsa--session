/*Meaning :- Given an array of size “N”; b[i] tells you the numbers of bananas in box “i” ; you have to select k which is your eating power 

And you have to select k in such a manner that you are able to eat all bananas in <=h hours; 

In 1 hour you can only eat k bananas! 

-> [5 8 6 3 1] h = 8 

K = 1 …………………………….Takes 23 hours. 
K = 2……………………………..Takes 13 hours. 
K = 3………………………………Takes 9 hours.
K = 4……………………………….Takes 8 hours.


Hence K = 4 is
*/

bool check(int k, vector<int>b, int h){
    int sum=0;
    for(int i=0;i<b.size();i++){
        if(b[i]%k==0){
            sum+=b[i]/k;

        }
        else{
            sum+=b[i]/k+1;
        }
    }

    return sum<=h;
}

int mineating(vector<int>b,int h){
    int itr=0;
    for(int i=0;i<b.size();i++){
        itr=max(itr,b[i]);

    }

    int low=1;
    int high=itr;
    int u=1;
    int answer=-1;

    while(low<=high && u==1){

        int mid=(low+high)/2;

        if(check(mid,b,h)==false){
            low=mid+1;
        }
        else{
            if(mid==1){
                answer=1;
                u=0;
            }
            else if(check(mid-1,b,h)==false){
                answer=mid;
                u=0;
            }
            else{
                high=mid-1;
            }
        }

    }
    return answer;
}