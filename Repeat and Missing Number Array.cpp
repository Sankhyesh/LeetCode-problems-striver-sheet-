vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int xor1;
    xor1 = A[0];
    int n = A.size();
    int i;

// firstly xor whole array 
    for(int i = 1; i < n; i++ ){
        xor1 = xor1 ^ A[i];
    }

    // now xor the result with numbers form 1 to n
// to get the xor of missing number and duplicate number

    for(i = 1; i<=n; i++){
        xor1 = xor1 ^ i;
    }

    int set_bit = xor1 & ~(xor1 - 1);


    // now to find the missing and duplicate number we will divide the 
    // elements into two sets by compairing a rightmost set bit of xor1
    // also get the xor of two sets

    int x = 0; // for set 1
    int y = 0; // for set 2

    for(i = 0; i<n; i++){
        if(A[i] & set_bit){
            // set 1
            x = x ^ A[i];
        }else{
            // set 2
            y = y ^ A[i];
        }
    }


// now xor with 1 to n for two sets 
    for(i = 1; i<=n; i++){
        if(i & set_bit){
            // set 1
            x = x ^ i;
        }else{
            // set 2
            y = y ^ i;
        }
    }

    // if numvers are swapped 

    int count = 0;
    for(int i = 0; i<n; i++){
        if(A[i] == x){
            count++;
        }
    }

    if(count == 0){
        return {y, x};
    }
    return {x, y};
}
