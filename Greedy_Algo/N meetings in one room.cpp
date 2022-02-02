// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    struct meeting{
        int start;
        int end;
        int pos;
    };
    public:
    bool static comparator(struct meeting m1, meeting m2){
        
        if(m1.end<m2.end)return true;
        else if(m1.end>m2.end)return false;
        else if(m1.pos<m2.pos)return true;
        else return false;
        
    }
    
    int maxMeetings(int s[], int e[], int n)
    {
        // Your code here
        struct meeting meet[n];
        for(int i = 0; i< n; i++){
            
            meet[i].start = s[i];
            meet[i].end = e[i];
            meet[i].pos = i;
        }
        
        sort(meet, meet+n, comparator);
        
        int limit = meet[0].end;
        int count = 1;
        
        for(int i = 1; i<n;i++){
            if(meet[i].start>limit){
                limit = meet[i].end;
                count++;
            }
        }
        return count;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
