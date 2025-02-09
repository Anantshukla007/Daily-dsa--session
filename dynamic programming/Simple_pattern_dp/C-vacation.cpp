/*Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.

The vacation consists of 
N days. For each 
i (
1≤i≤N), Taro will choose one of the following activities and do it on the 
i-th day:

A: Swim in the sea. Gain 
a 
i
​
  points of happiness.
B: Catch bugs in the mountains. Gain 
b 
i
​
  points of happiness.
C: Do homework at home. Gain 
c 
i
​
  points of happiness.
As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

Find the maximum possible total points of happiness that Taro gains.

Constraints
All values in input are integers.
1≤N≤10 
5
 
1≤a 
i
​
 ,b 
i
​
 ,c 
i
​
 ≤10 
4
 
Input
Input is given from Standard Input in the following format:

N
a 
1
​
  
b 
1
​
  
c 
1
​
 
a 
2
​
  
b 
2
​
  
c 
2
​
 
:
a 
N
​
  
b 
N
​
  
c 
N
​
 
Output
Print the maximum possible total points of happiness that Taro gains.

Sample Input 1
Copy
3
10 40 70
20 50 80
30 60 90
Sample Output 1
Copy
210*/


#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int a[n+1];
    int b[n+1];
    int c[n+1];
    int i=1;

    while(i<=n){
        cin>>a[i]>>b[i]>>c[i];
        i++;
    }

    int dpa[n+1]={0};
    int dpb[n+1]={0};
    int dpc[n+1]={0};

    dpa[1]=a[1];
    dpb[1]=b[1];
    dpc[1]=c[1];

    i=2;
    while(i<=n){
        dpa[i]=a[i]+max(dpb[i-1],dpc[i-1]);
        dpb[i]=b[i]+max(dpa[i-1],dpc[i-1]);
        dpc[i]=c[i]+max(dpa[i-1],dpb[i-1]);
        i++;
    }

    cout<<max(dpa[n],dpb[n],dpc[n]);
    return 0;
}