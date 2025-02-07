int cl(vector<int>b, int n, int k){

    int low=0;
    int high=n-1;

    while(low<=high){

        int mid=(low+high)/2;

        int l1=lower_bound(b[mid]);
        int h1=upper_bound(b[mid])-1;

        int d=abs(l1-h1)+1;

        if(d<k){
            return b[mid];
        }

        if(h1-l1%k ==0 ){
            low=h1+1;
        }
        else{
            high=l1-1;
        }
    }

    return -1;

}