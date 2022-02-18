int countSmall(vector<int> &row, int mid){
        int l = 0, h = row.size() - 1;
        while(l <= h){
            int md = (l+h)>>1;
            if(row[md] <= mid){
                l = md+1;
            }else{
                h = md-1;
            }
        }
        return l;
}

int Solution::findMedian(vector<vector<int> > &A) {
    int low = 1;
    int high = 1e9;
    int n = A.size();
    int m = A[0].size();

    while(low <= high){
        int mid = (low + high) >> 1;
        int count = 0;
        for(int i=0; i<n; i++){
            count += countSmall( A[i], mid);
        }
        if(count <= (n*m)/2){
            low = mid+1;
        }else{
            high = mid-1;
        }

    }
    return low;
}
