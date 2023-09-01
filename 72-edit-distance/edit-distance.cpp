class Solution {
public:
    int solveUsingRec(string word1,string word2,int i,int j){
        if(i==word1.length()){
            return word2.length()-j;
        }
        if(j==word2.length()){
            return word1.length()-i;
        }
        int ans=0;
        if(word1[i]==word2[j]){
            ans=solveUsingRec(word1,word2,i+1,j+1);
        }
        else{
            int insert=1+solveUsingRec(word1,word2,i,j+1);
            int replace=1+solveUsingRec(word1,word2,i+1,j+1);
            int deleted=1+solveUsingRec(word1,word2,i+1,j);
            ans=min(insert,min(replace,deleted));
        }
        return ans;
    }
    int solveUsingMem(string word1,string word2,int i,int j,vector<vector<int>>&dp){
         if(i==word1.length()){
            return word2.length()-j;
        }
        if(j==word2.length()){
            return word1.length()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(word1[i]==word2[j]){
            ans=solveUsingMem(word1,word2,i+1,j+1,dp);
        }
        else{
            int insert=1+solveUsingMem(word1,word2,i,j+1,dp);
            int replace=1+solveUsingMem(word1,word2,i+1,j+1,dp);
            int deleted=1+solveUsingMem(word1,word2,i+1,j,dp);
            ans=min(insert,min(replace,deleted));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        if(word1.length()==0){
            return word2.length();
        }
        if(word2.length()==0){
            return word1.length();
        }
        int i=0,j=0;
        //return solveUsingRec(word1,word2,i,j);
        vector<vector<int>> dp(word1.length(),vector<int>(word2.length(),-1));
        return solveUsingMem(word1,word2,i,j,dp);
    }
};