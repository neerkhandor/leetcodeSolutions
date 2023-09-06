/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* build(int &i,int min,int max,vector<int>& preorder){
        if(i>=preorder.size()){
            return nullptr;
        }
        //whenever there is question to build bst then we have to create root
        TreeNode* root=nullptr;
        if(preorder[i]>min && preorder[i]<max){
            root=new TreeNode(preorder[i]);
            i++;
            root->left=build(i,min,root->val,preorder);
            root->right=build(i,root->val,max,preorder);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      //we have to traverse the array so we will have a i 
      int i=0;
      int min=INT_MIN;
      int max=INT_MAX;
      return build(i,min,max,preorder);
    }
};