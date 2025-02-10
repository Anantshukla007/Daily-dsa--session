/*Given a string s(only consists of “a” and “b”) ; find the largest substring such that there are at max only 2 continuous occurrences of “a” and “b” 

-> “aabbaaa” -> Whole string is not valid ; but part of the string->substring -> “aabbaa” -> this is valid -> length is 6.
*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    int n=s.size();

    int dpa1[n]={0};
    int dpa2[n]={0};
    int dpb1[n]={0};
    int dpb2[n]={0};

    if(s[0]=='a'){
        dpa1[1]=1;

    }
    if(s[0]=='b'){
        dpb1[1]=1;
    }


    int r=0;
    int i=1;

    int answer=1;

    while(i<=n-1){
        if(s[i]=='a'){
            dpa1[i]=1+max(dpb1[i-1],dpb2[i-1]);


            if(i>=2 && s[i-1]=='a'){
                dpa2[i]=2+max(dpb1[i-2],dpb2[i-2]);

            }
            else if(s[i-1]='a'){
                dpa2[i]=2;
            }
            dpb1[i] = 0 ; 
            dpb2[i] = 0 


        }
        else {
 
            dpb1[i] = 1 + max(dpa1[i-1],dpa2[i-1]);
 
            if(i>=2 && s[i-1]=='b'){
                dpb2[i] = 2 + max(dpa1[i-2],dpa2[i-2]);
            }
            else if(s[i-1]=='b'){
                dpb2[i] = 2 ; 
            }
            dpa1[i] = 0 ; 
            dpa2[i] = 0 ; 
 
 
        }

        answer = my(dpa1[i],dpa2[i],dpb1[i],dpb2[i]);
        r = max(r,answer);
        i++;

    }
    cout<<r;
    return 0;
}