//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i , int j ,   vector<vector<int>> &vis , vector<vector<int>>& grid, vector<pair<int, int>> &vec, int si , int sj )
    {
        vis[i][j] =1;
        vec.push_back({i-si, j-sj});
         int n = grid.size();
        int m = grid[0].size();
        
        int di[] = {-1,0,1,0};
        int dj[] = {0,-1,0,1};
        
        for(int k =0;k<4;k++)
        {
            int ni = di[k]+i;
            int nj = dj[k]+j;
            
            if(ni>=0 and ni<n and nj>=0 and nj<m and grid[ni][nj] ==1 and !vis[ni][nj])
            {
                dfs(ni,nj,vis,grid,vec,si,sj);
            }
        }
    }    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        set<vector<pair<int, int>>> st;
        
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(!vis[i][j] and grid[i][j] == 1)
                {
                    vector<pair<int,int>> vec;
                    dfs(i,j,vis,grid,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};

    


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends