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
    
    class info{
        
        public: 
          int sum;
          int size;
        int res;
        
        info(int sum,int size,int res){
            this->sum=sum;
            this->size=size;
            this->res=res;
        }
    };
    
    
    info avgSubTree_(TreeNode *root){
        info curr(0,0,0);
        if(root==NULL){
            
             return curr;
        }
        
        info left=avgSubTree_(root->left);
        info right=avgSubTree_(root->right);
        
          curr.sum=left.sum+right.sum+root->val;
            curr.size=left.size+right.size+1;
            curr.res=left.res+right.res;
        
        if((left.sum+right.sum+root->val)/(left.size+right.size+1)==root->val){
            
            curr.res+=1;
              
        }
        
        return curr;
    }
    
    int averageOfSubtree(TreeNode* root) {
        
        return avgSubTree_(root).res;
        
        
    }
};