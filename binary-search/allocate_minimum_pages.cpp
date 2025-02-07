/*Given an array arr[] and an integer k, where arr[i] denotes the number of pages of a book and k denotes total number of students. All the books need to be allocated to k students in contiguous manner, with each student getting at least one book.

The task is to minimize the maximum number of pages allocated to a student. If it is not possible to allocate books to all students, return -1.

Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Books can be distributed in following ways:


[12] and [34, 67, 90] – The maximum pages assigned to a student is  34 + 67 + 90 = 191.
[12, 34] and [67, 90] – The maximum pages assigned to a student is 67 + 90 = 157.
[12, 34, 67] and [90] – The maximum pages assigned to a student is 12 + 34 + 67 = 113.
The third combination has the minimum pages assigned to a student which is 113.


Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Since there are more students than total books, it’s impossible to allocate a book to each student.


Input: arr[] = [22, 23, 67], k = 1
Output: 112
Explanation: Since there is only 1 student, all books are assigned to that student. So, maximum pages assigned to a student is 22 + 23 + 67 = 112.*/

/*if you have solved the aggrsssive cow then you can surely solve this one to here the thing is to allocate pages 
now how many pages riser the question if there was one person all the pages could have been allcated to him so that adds up to totals sum right
now as your people increase you decide to  make a cut yet the maxium cant be greater then the total sum right 
now just in this range of one to this total sum lies the answer now simpily put binary search over it
*/

#include<bits/stdc++.h>
using namespace std;


bool check(int a[], int n,int m , int mid){// in this type of question the main part is not binary search the main part is this check function
    int cnt=0;
    int sum=0;
    for(int i=0;i<n;i++){
        if(a[i]>mid){
            return false;

        }
        sum+=a[i];
        if(sum>mid){
            cnt++;
            sum=a[i];

        }
        if(cnt>m)return false;

    }
    return true;
}


int findminimu(int a[],int n,int m){
    int high=0;
    
    if(n<m){
        return -1;
        
    }
        int low=a[0];
        for(int i=0;i<n;i++){
            high+=a[i];
            low=min(a[i],low)
        }
        while(low<=high){
            int mid=(low+high)/2;
            if(check(a,n,m,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
    
    return ans;

}

int main(){
    int n,m;
    cin>>n;
    int a[100000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    cout<<findminimu(a,n,m);
}