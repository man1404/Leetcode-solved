//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int solve(int i , int j ,int prev , int m , int n , int arr1[], int arr2[] , vector<vector<vector<int>>> &dp)
    {
        if(i == m|| j == n)
            return 0;
        
        if(dp[i][j][prev+1] != -1)
            return dp[i][j][prev+1];
        int p =0;
        if(arr1[i] == arr2[j] and (arr2[j] > arr2[prev] || prev == -1))
            p = 1+solve(i+1,j+1,j,m,n, arr1,arr2,dp);
        
        int np = max(solve(i+1,j,prev , m,n,arr1,arr2,dp) ,solve(i,j+1,prev, m,n,arr1,arr2,dp));
        return dp[i][j][prev+1] = max(p,np);
    }
    int LCIS(int arr1[], int m, int arr2[], int n) {
        // code here
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>> (n+1,vector<int>(n+1,-1)));
        return solve(0,0,-1,m,n,arr1,arr2,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m;
        int arr1[m];
        for (int i = 0; i < m; i++) {
            cin >> arr1[i];
        }
        cin >> n;
        int arr2[n];
        for (int i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        cout << ob.LCIS(arr1, m, arr2, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends