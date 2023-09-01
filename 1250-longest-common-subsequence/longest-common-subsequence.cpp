class Solution {
public:
    int solveUsingRecursion(string text1,string text2,int i,int j){
        //agar pehli string khatam hogayi then 0 return kardo
        if(i==text1.length())
            return 0;
        if(j==text2.length())
            return 0;
        if(text1[i]==text2[j]){
            return 1+solveUsingRecursion(text1,text2,i+1,j+1);
        }
        else{
            return max(solveUsingRecursion(text1,text2,i+1,j),solveUsingRecursion(text1,text2,i,j+1));
        }
    }
     int solveUsingMem(string &text1,string &text2,int i,int j,vector<vector<int>>&dp){
        //agar pehli string khatam hogayi then 0 return kardo
        if(i==text1.length())
            return 0;
        if(j==text2.length())
            return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(text1[i]==text2[j]){
            ans= 1+solveUsingMem(text1,text2,i+1,j+1,dp);
     
        }
        else{
            ans= max(solveUsingMem(text1,text2,i+1,j,dp),solveUsingMem(text1,text2,i,j+1,dp));   
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int solveUsingTab(string text1,string text2){
        vector<vector<int> >dp(text1.length()+1,vector<int>(text2.length()+1,0));
        //here we dont need base case as our base case is already handled since we are initiallizing with 0
        //text 1 is going from 0 to text1.length and similarly text2 is also going from 0 to text2.length
        //so for tabulation sol we will do reverse
        
        for(int i=text1.length()-1;i>=0;i--){
            for(int j=text2.length()-1;j>=0;j--){
            int ans=0;
                 if(text1[i]==text2[j]){
                 ans= 1+dp[i+1][j+1];
             }
             else{
               ans= max(dp[i+1][j],dp[i][j+1]);
               }
               dp[i][j]=ans;
            }
        }

    return dp[0][0];
    }
    int solveUsingSpaceOptimized(string &text1,string &text2){
        vector<int>curr(text2.length()+2,0);
        vector<int>next(text2.length()+2,0);
         for(int i=text1.length()-1;i>=0;i--){
            for(int j=text2.length()-1;j>=0;j--){
            int ans=0;
                 if(text1[i]==text2[j]){
                 ans= 1+next[j+1];
             }
             else{
               ans= max(next[j],curr[j+1]);
               }
               curr[j]=ans;
            }
            //mein yehi pakka bhulunga
            //shifting 
            //since ham ulta ja raha hai
            next=curr;
        }

    return curr[0];

    }
    int longestCommonSubsequence(string text1, string text2) {
        int i=0;
        int j=0;
        // return solveUsingRecursion(text1,text2,i,j);   
         vector<vector<int> >dp(text1.length(),vector<int>(text2.length(),-1));
        // return solveUsingMem(text1,text2,i,j,dp);
        //return solveUsingTab(text1,text2);
        return solveUsingSpaceOptimized(text1,text2);

    }
};