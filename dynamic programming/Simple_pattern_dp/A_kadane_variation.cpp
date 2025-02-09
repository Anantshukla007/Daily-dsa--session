/*Understanding of the problem:-> You are given “B” queries; you have to perform some of them in order ; and make your initial integer 1 as large as possible! 

-> + x 
-> - x 
-> * x 
->/ x
->Negate ie multiply by -1
*/


//now if you know kadane then this is just a variation of that with multipple operation nothing more if you dont know kadane then please first watch a video of it


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i, l, r) for ((i) = (l); (i) <=(r); (i)++)
#define rep1(i, r, l) for ((i) = (r); (i) >=(l); (i)--)

ll max(ll a,ll b,ll c)
{
    return max(a,max(b,c)) ; 
}
ll min(ll a,ll b,ll c)
{
    return min(a,min(b,c)) ;
}

int main()
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL);
    cout.tie(NULL);
    ll t ; 
    cin>>t;
    while(t--)
    {
    ll b; 
    cin>>b ; 
    ll i ; 
    ll dp1[b+1];
    ll dp2[b+1];
    dp1[0]=1;
    dp2[0]=dp1[0];
    rep(i,1,b)
    {
        char g ; 
        cin>>g ; 
        if(g=='+')
        { ll e ; cin>>e;
            dp1[i] = max(dp1[i-1]+e,dp2[i-1]+e,dp1[i-1]) ; 
            dp2[i] = min(dp1[i-1]+e,dp2[i-1]+e,dp2[i-1]) ;   
        }
        else if(g=='-')
        { ll e ; cin>>e;
            dp1[i] = max(dp1[i-1]-e,dp2[i-1]-e,dp1[i-1]) ; 
            dp2[i] = min(dp1[i-1]-e,dp2[i-1]-e,dp2[i-1]) ; 
        }
        else if(g=='*')
        { ll e ; cin>>e;
            dp1[i] = max(dp1[i-1]*e,dp2[i-1]*e,dp1[i-1]) ; 
            dp2[i] = min(dp1[i-1]*e,dp2[i-1]*e,dp2[i-1]) ; 
        }
        else if(g=='/')
        { ll e ; cin>>e;
            dp1[i] = max(dp1[i-1]/e,dp2[i-1]/e,dp1[i-1]) ; 
            dp2[i] = min(dp1[i-1]/e,dp2[i-1]/e,dp2[i-1]) ; 
        }
        else{
            dp1[i] = max(-1*dp1[i-1],-1*dp2[i-1], dp1[i-1]) ; 
            dp2[i] = min(-1*dp1[i-1],-1*dp2[i-1], dp2[i-1]) ;
        }
    }
    cout<<dp1[b]; 
 cout<<"\n";    
}
      							
	return 0;
}
