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
    
    TreeNode *flatten_(TreeNode *root){
        
        if(root==NULL){
            return NULL;
        }
        
        TreeNode * left=flatten_(root->left);
        TreeNode *right=flatten_(root->right);
        
        TreeNode *tail=left;
        while(tail!=NULL&&tail->right!=NULL){
            tail=tail->right;
        }
        
        if(tail==NULL){
            return root;
        }
        
        
        root->left=NULL;
        root->right=left;
        tail->right=right;
        
        return root;
        
      
        
        
        
        
        
    }
    
    void flatten(TreeNode* root) {
        
        
         flatten_(root);
    }
};