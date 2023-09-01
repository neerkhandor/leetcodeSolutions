class Solution {
public:
    int solveUsingSpaceOptimized(string& str1,string& str2){
        vector<int>curr(str2.length()+1,0);
        vector<int>next(str2.length()+1,0);
        for(int i=str1.length()-1;i>=0;i--){
            for(int j=str2.length()-1;j>=0;j--){
                int ans=0;
                if(str1[i]==str2[j]){
                    ans=1+next[j+1];
                }
                else{
                    ans=max(curr[j+1],next[j]);
                }
                curr[j]=ans;
            }
            next=curr;
        }
    return next[0];
    }
    int longestPalindromeSubseq(string s) {
        string str1=s;
        reverse(s.begin(),s.end());
        string str2=s;

        return solveUsingSpaceOptimized(str1,str2);
    }
};