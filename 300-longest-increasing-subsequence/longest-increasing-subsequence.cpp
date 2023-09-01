class Solution {
public:
    int solveUsingRec(vector<int>& nums,int curr,int prev){
        if(curr>=nums.size()){
            return 0;
        }
        //include
        int include=0;
        if(prev==-1|| nums[curr]>nums[prev])
            include=1+solveUsingRec(nums,curr+1,curr);
        //exclude
        int exclude=0+solveUsingRec(nums,curr+1,prev);
        int ans=max(include,exclude);
        return ans;
    }
    int solveUsingMem(vector<int>& nums,int curr,int prev,vector<vector<int>>& dp){
        if(curr>=nums.size()){
            return 0;
        }
        //include
        if(dp[prev+1][curr]!=-1){
            return dp[prev+1][curr];
        }
        int include=0;
        if(prev == -1 || nums[curr]>nums[prev])
            include=1+solveUsingMem(nums,curr+1,curr,dp);
        //exclude
        int exclude=0+solveUsingMem(nums,curr+1,prev,dp);
        int ans=max(include,exclude);
        dp[prev+1][curr]=ans;
        return dp[prev+1][curr];
    }
    int lengthOfLIS(vector<int>& nums) {
        int curr=0;
        int prev=-1;
        // return solveUsingRec(nums,curr,prev);
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+2,-1));
        return solveUsingMem(nums,curr,prev,dp);
    }
};