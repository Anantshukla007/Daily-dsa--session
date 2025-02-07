/*Given a row-wise sorted matrix where the number of rows and columns is always odd, find the median of the matrix.

Examples:

Input: mat = [[1, 3, 5], [2, 6, 9], [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. */


#include<bits/stdc++.h>
using namespace std;


int findmedian(vector<vetor<int>>a){
    int l=1;
    int r=1e9;

    int median=0;


    int n=a.size();
    int m=a[0].size();

    int total=n*m;

    while(l<=r){
        int mid=(l+r)/2;

        int lessthanequal=0;

        for(int row=0;row<n;row++){
            int ub=upper_bound(a[row].begin(),a[row].end(),mid)-a[row].begin();

            lessthanequal+=ub;

            if(lessthanequal>total/2){
                median=mid;
                r=mid-1;

            }
            else{
                l=mid+1;
            }

        }
    }
    return median;


}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>matrix(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }

    cout<<findmedian(matrix)<<endl;
    return 0;
}