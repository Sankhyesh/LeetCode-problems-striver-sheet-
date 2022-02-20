bool isAllocatePossible(int mid,vector<int> &A, int stud){
    int allocateStud = 0, pages = 0;

    for(int i = 0; i<A.size(); i++){
        

        if(pages+A[i] > mid){
            allocateStud += 1;
            pages = A[i];
            if(pages > mid){
            return false;
                }
        }else{
            pages += A[i];
        }
    }

    if(allocateStud < stud){
        return true;
    }
    return false;
}

int Solution::books(vector<int> &A, int B) {
    
    if(B>A.size()) return -1;

    int low = A[0];
    int high = 0;
    
    for(int i=0;i<A.size();i++){
        high += A[i];
        low = min(A[i], low);
       
    }
     
    int res = -1;
    while(low <= high){
        int mid = (low + high)>>1;
        if(isAllocatePossible(mid, A, B)){
            res = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }       
        // cout<<high << " "<<low<< " "<<res; 
    }
    return res;

}
