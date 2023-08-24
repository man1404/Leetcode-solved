//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	  bool in(int x , int y, int n )
    {
        if(x>=0 and y>=0 and x<n and y<n)
            return true;
        
        return false;
    }
    double solve(int n , int k , int row , int col , vector<vector<vector<double>>> &dp)
    {
        if(k == 0)
            return 1;
        
        if(dp[row][col][k]!=-1)
            return dp[row][col][k];
 
        if(k>0)
        {
               double prob = 0.0;
            int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
            int dy[] = { 2, 1, -1, -2, -2, -1, 1, 2 };

            for(int i =0;i<8;i++)
            {
                int nx = row+dx[i];
                int ny = col+dy[i];

                if(in(nx,ny,n))
                    prob += 0.125*solve(n, k-1, nx, ny , dp);
            }
            dp[row][col][k] = prob;
        }
        return dp[row][col][k] ;
    }
	double findProb(int N,int start_x, int start_y, int steps)
	{
	    // Code here
	    vector<vector<vector<double>>> dp(N+1,vector<vector<double>> (N+1 , vector<double> (steps+1,-1)));
        return solve(N,steps,start_x,start_y,dp);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N, start_x, start_y, steps;
		cin >> N >> start_x >> start_y >> steps;
		Solution ob;
		double ans = ob.findProb(N, start_x, start_y, steps);
		cout << fixed << setprecision(6) << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends