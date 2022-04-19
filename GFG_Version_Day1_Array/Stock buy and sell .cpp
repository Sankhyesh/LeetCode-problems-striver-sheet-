// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        
        
        int mini = A[0];
        int maxPro = A[0];
        
        vector<vector<int> > ans;
        
        if(n == 1){
            return ans;
        }
        
        // traverseing throgh the given array price;
        int i = 0;
        
        while(i<n-1){
            
            // / we are checking the upto the last elemnt
            // that's y we are taking lesser than n -1
            
            // skip those days where  downtrend
            // eg - 90, 80, 70, 60, 50, 40
            while((i<n-1) && A[i+1] <= A[i]){
                i++;
            }// move tille the next elemnt is not greater
            
            
            
            // suppose if we already reached the end then break the loop 
            // if we reached the end, break
            // as no further solution ppossibel 
            if(i == n -1){
                break;
            }
            
            // bcz we know next day is
            // is greater then curr so we can
            // buy on that day 
            
            int buy = i;
            
            // move to the next day
            i++;
            
            // now we haveto sell it on the day where 
            // the next day is smaller
            while((i<n) && (A[i] >= A[i - 1])){
                i++;
            }
            
            int sell = i-1;
            // push the answer always
            ans.push_back({buy, sell});
        }
        return ans;
        
     
    }
};

// { Driver Code Starts.

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for(int i=0; i<n-1; i++)
        {
            int x = A[i+1]-A[i];
            if(x>0)
                p += x;
        }
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            cout<<check(ans,A,p);
        }cout<<endl;
    }
    return 0;
}

  // } Driver Code Ends
