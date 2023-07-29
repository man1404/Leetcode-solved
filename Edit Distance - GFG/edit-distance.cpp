//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(string s , string t , int i , int j , int m , int n, vector<vector<int>> &dp)
    {
        if(i == m and j==n)
            return 0;
        if(i>m||j>n)
            return INT_MAX;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i] == t[j])
        {
            return dp[i][j] = solve(s,t, i+1,j+1, m , n, dp);
        }
        else
        {
            int ins = solve(s,t,i,j+1,m,n,dp);
            int del = solve(s,t,i+1,j,m,n,dp);
            int rep = solve(s,t,i+1,j+1,m,n,dp);
            dp[i][j] = 1+min({ins,del,rep});
        }
        
        return dp[i][j];
            
    }
    int editDistance(string s, string t) {
        // Code here
        int m=s.size();
        int n = t.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(s,t,0,0,m,n,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends