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
    
    TreeNode *construct(TreeNode *root,unordered_map<int,pair<int,int>> &mp){
        
        
        if(mp[root->val].first!=0){
            TreeNode *node=new TreeNode(mp[root->val].first);
            
            root->left=node;
            construct(node,mp);
        }
         if(mp[root->val].second!=0){
                TreeNode *node=new TreeNode(mp[root->val].second);
            root->right=node;
            construct(node,mp);
         }
        
        return root;
        
    }
    
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        
        unordered_map<int,pair<int,int>> mp;
        
           unordered_set<int> st;
        
        for(vector<int> inf:d){
            
            st.insert(inf[1]);
            
            if(inf[2]==1){
                mp[inf[0]].first=inf[1];
                
            }
            else{
                mp[inf[0]].second=inf[1];
            }
        }
        int root;
        for(vector<int> inf:d){
            
            if(st.find(inf[0])==st.end()){
                root=inf[0];
                break;
            }
            
        }
        
        
        
        
        
        TreeNode *rootNode=new TreeNode(root);
        
          
        construct(rootNode,mp);
        
        return rootNode;
        
        
        
        
    }
};