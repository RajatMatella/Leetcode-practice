// Approach - 1(recursion)

bool isSafe(int i, int j, int m, int n){
        if((i>=0 && i<m) && (j>=0 && j<n))
            return true;
        
        return false;
    }
    
    void solve(int i, int j, int m, int n, int &ans){
        if(i==m-1 && j==n-1){
            ans++;
            return;
        }
        
        //right move
        if(isSafe(i,j+1,m,n))
            solve(i,j+1,m,n,ans);
        
        //down move
        if(isSafe(i+1,j,m,n))
            solve(i+1,j,m,n,ans);
        
        
        return;
    }
    
    int uniquePaths(int m, int n) {
        if(m==1 && n==1)
            return 1;
        
        if(n==1 || m==1)
            return 1;
        
        int ans=0;
        solve(0,0,m,n,ans);
        return ans;
    }


// Approach - 2(DP memoization)

int solve(int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i==m-1 && j==n-1){
            return 1;
        }
        
        if(i>=m || j>=n)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // current pos = prev-left + prev-up 
        dp[i][j] = solve(i+1,j,m,n,dp) + solve(i,j+1,m,n,dp);
        
        return dp[i][j];
    }
    
    int uniquePaths(int m, int n) {
        if(m==1 && n==1)
            return 1;
        
        if(n==1 || m==1)
            return 1;
        
        vector<vector<int>> dp(m, vector<int>(n,-1));
        
        return solve(0,0,m,n,dp);


// Approach - 3 (tabulation)
int uniquePaths(int m, int n) {
        if(m==1 && n==1)
            return 1;
        
        if(n==1 || m==1)
            return 1;
        
        vector<vector<int>> dp(m, vector<int>(n,1));
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n ;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
}
