/*- Given two arrays of size “N” ; “a” and “b” ; select any k indices and find maximum value of this function :- 

min(a[i1] + a[i2] + a[i3] + …………… + a[ik] , b[i1] + b[i2] + b[i3] + ……..b[ik]) 

Input - N = 5 K = 3 
[6 3 6 5 1]
[1 4 5 9 2]

O/p - (0,2,3) = min(6 + 6 + 5, 1 + 5 + 9) = min(17,15) = 15

[10 2 4]
[1 9 6]

K = 1 

O/P = 4. 

*/


#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 30;
const int MAXK = 15;
const int MAXSUM = 150;
bool dp[MAXN+1][MAXK+1][MAXSUM + 1][MAXSUM + 1];
 
 
int main() {
    int n, k;
    cin >> n >> k;
    int a[n+1], b[n+1];
 
    dp[0][0][0][0] = true;
    for(int i = 1; i<=n; i++) {
        cin >> a[i];
        dp[i][0][0][0] = true;
    }
 
    for (int i = 1; i<=n; i++) {
        cin >> b[i];
    }
 
    for (int i = 1; i <=n; i++) {
        for (int pick = 1; pick <= k; pick++) {
            int sum1 = 0;
            while (sum1 <= MAXSUM) {
                int sum2 = 0;
                while (sum2 <= MAXSUM) {
	                    if(dp[i-1][pick][sum1][sum2]==true){
	                    	//ith index is not included in the k indices we are picking
	                    	dp[i][pick][sum1][sum2] = true;
	                    }
	else if((sum1-a[i])>=0 && (sum2-b[i])>=0 && (dp[i-1][pick-1][sum1-a[i]][sum2-b[i]]==true))
		                 {
		                    dp[i][pick][sum1][sum2] = true;
		                 }
                    sum2++;
                }
                sum1++;
            }
        }
    }
 
    int final_answer = 000000;
    for (int sum1 = 0; sum1 <= MAXSUM; sum1++) {
        for (int sum2 = 0; sum2 <= MAXSUM; sum2++) {
            if (dp[n][k][sum1][sum2]==true) {
                cout<<sum1<<" "<<sum2<<"\n";
                int answer = min(sum1, sum2);
                final_answer = max(final_answer, answer);
            }
        }
    }
 
    cout << final_answer << endl;
 
    return 0;
}