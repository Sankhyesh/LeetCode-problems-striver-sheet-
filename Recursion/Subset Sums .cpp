// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
// class Solution
// {
// public:
//     vector<int> res;
//     void findSum(int i, vector<int> arr, vector<int> ds, int n){
        
//         if(i == n){
//             int sum = 0;
//             for (auto i : ds){
//                 sum += i;        
//             }
//             res.push_back(sum);
//             return;
//         } 
        
//         ds.push_back(arr[i]);
        
//         findSum(i+1, arr, ds, n);
        
//         ds.pop_back();
        
//         findSum(i+1, arr, ds, n);
//     }
//     vector<int> subsetSums(vector<int> arr, int N)
//     {
//         vector<int> ds;
//         findSum(0,arr, ds,N);
//         return res;
//     }
// };

/// optimal soution 
class Solution
{
public:
    void findSum(int i, vector<int> &arr, int sum, vector<int> &ss, int n){
        
        if(i == n){
            ss.push_back(sum);
            return;
        } 
        
        sum += arr[i];
        findSum(i+1, arr,sum, ss, n);
        
        sum -= arr[i];
        findSum(i+1, arr, sum, ss, n);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> subsetsum;
        findSum(0, arr, 0, subsetsum, N);
        return subsetsum;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
