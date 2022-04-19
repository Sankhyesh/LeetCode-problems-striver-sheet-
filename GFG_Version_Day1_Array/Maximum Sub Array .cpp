// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	   int start, end, i, j;
	   start = end = i = j = 0;
	   long long currSum, maxSum;
	   currSum = maxSum = 0;
	   
	   while(j<n){
	       if(a[j] >= 0){
	        currSum = currSum + a[j];
	        if(currSum >= maxSum){
	            start = i;
	            end = j;
	            maxSum = currSum;
	        }
	           
	       }else{
	           currSum = 0;
	           i = j+1;
	       }
	       j++;
	   }
	   vector<int> res;
	   if(start == end && a[start]<0){
	       res.push_back(-1);
	       return res;
	   }
	   
	   for(int i = start; i<=end; i++){
	       res.push_back(a[i]);
	   }
	   //if(!res.size()){
	   //    res.push_back(-1);
	   //}
	    return res;
	}
};

// { Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}
  // } Driver Code Ends
