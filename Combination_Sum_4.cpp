// Brute force (recursive)

class Solution {
public:
    void solve(vector<int>& nums, int n, int target, int &ans){
        if(target<0)
            return;
        
        if(target==0){
            ans++;
            return;
        }
        
        for(int i=0;i<n;i++){
            solve(nums,n,target-nums[i],ans);
        }
        
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 1)
            return (nums[0]==target)? 1:0;
        
        int ans=0;
        solve(nums,size,target,ans);
        
        return ans;
    }
};

// DP (memoization)

class Solution {
public:
    int solve(vector<int>& nums, int n, int target, vector<int> &dp){
        if(target<0)
            return 0;
        
        if(target==0){
            return 1;
        }
        
        if(dp[target] != -1)
            return dp[target];
        
        int ans=0;
        for(int i=0;i<n;i++){
            ans += solve(nums,n,target-nums[i],dp);
        }
        
        dp[target]=ans;
        return dp[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 1)
            return (nums[0]==target)? 1:0;
        
        vector<int> dp(target+1, -1);
        int ans=0;
        
        return solve(nums,size,target,dp);
    }
};

