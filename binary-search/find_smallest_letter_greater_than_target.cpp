/*You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.

Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.*/


char nextgreaterletter(vector<char>letters, char target){

    int low=0;
    int high=letters.size()-1;

    if(letters[0]>target || target>= letters[letters.size()-1]){
        return letters[0];
    }
    char ans;
    while(low<=high){
        int mid=(low+high)/2;
        if(letters[mid]>target){
            ans=letters[mid];
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}