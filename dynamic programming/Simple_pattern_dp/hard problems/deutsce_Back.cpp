/*There are N tasks. To be performed on N days; each day you perform a single task 

Each day you have three choices; either perform the easy[i] , medium [i] , hard[i] 

For doing each task you get some points. 

Maximize the total points. 

On day “i” you can do a hard task if and only if the day before the previous day you did an easy task 

On day “i” you can do a medium task if and only if the day before you did easy task and the day before that you did medium task 
*/


//now this problem is easy it's just too lengthy to code 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// Function to calculate the maximum points
int maximizePoints(int N, const vector<int>& easy, const vector<int>& medium, const vector<int>& hard) {
    if (N == 0) return 0;
 
    vector<int> dp_easy(N + 1, 0);
    vector<int> dp_medium(N + 1, 0);
    vector<int> dp_hard(N + 1, 0);
    
    //starting first few index  - No rule. 
    dp_easy[1] = easy[1];
    dp_medium[1] = medium[1];
    dp_hard[1] = hard[1];
 
    dp_easy[2] = easy[2] + max({easy[1], medium[1], hard[1]});
    dp_medium[2] = medium[2] + max({easy[1], medium[1], hard[1]});
    dp_hard[2] = hard[2] + max({easy[1], medium[1], hard[1]});
 
    dp_easy[3] = easy[3] + max({dp_easy[2], dp_medium[2], dp_hard[2]});
    dp_medium[3] = medium[3] + easy[2] + medium[1];
    dp_hard[3] = hard[3] + easy[1] + max({easy[2], medium[2], hard[2]});
    
    
    for (int i = 4; i <= N; ++i) {
        dp_easy[i] = easy[i] + max({dp_easy[i - 1], dp_medium[i - 1], dp_hard[i - 1]});
 
        dp_medium[i] = medium[i] + easy[i - 1] + dp_medium[i - 2];
 
        dp_hard[i] = hard[i] + easy[i - 1] + dp_easy[i - 2];
 
        dp_hard[i] = max(dp_hard[i], hard[i] + medium[i - 1] + easy[i - 2] + dp_medium[i - 3]);
        dp_hard[i] = max(dp_hard[i], hard[i] + hard[i - 1] + easy[i - 2] + dp_easy[i - 3]);
 
    }
 
    return max({dp_easy[N], dp_medium[N], dp_hard[N]});
}
 
int main() {
    int N;
    cin>>N;
    vector<int> easy(N+1), medium(N+1), hard(N+1);
 
    for(int i=1;i<=N;i++){
    	cin>>easy[i];
    }
 
    for(int i=1;i<=N;i++){
    	cin>>medium[i];
    }
 
    for(int i=1;i<=N;i++){
    	cin>>hard[i];
    }
    cout << "Maximum points: " << maximizePoints(N, easy, medium, hard) << endl;
 
    return 0;
}
 