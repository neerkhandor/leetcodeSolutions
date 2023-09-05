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
    int maxVal(TreeNode* &root){
        if(root==NULL){
            //to koi max val milega hi nahi
            return -1;
        }
        TreeNode*temp=root;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        return temp->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
        return NULL;
    }
    if(root->val==key){
        //if we found the target we will have 4 cases
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->left!=NULL && root->right==NULL){
            TreeNode*child=root->left;
            delete root;
            return child;
        }
        else if(root->left==NULL && root->right!=NULL){
            TreeNode* child=root->right;
            delete root;
            return child;
        }
        else{
            root->val=maxVal(root->left);
            //now we have to delete this maxVal as its value is duplicated
            //and we will be calling it from leftsubtree because we are considering
            //inorder predecessor
            //and now the data to be deleted is the maxVal
            root->left=deleteNode(root->left,maxVal(root->left));
            return root;
        }
    }
    else if(key > root->val){
        root->right=deleteNode(root->right,key);
    }
    else if(key < root->val){
        root->left=deleteNode(root->left,key);
    }
    return root; 
    }
};