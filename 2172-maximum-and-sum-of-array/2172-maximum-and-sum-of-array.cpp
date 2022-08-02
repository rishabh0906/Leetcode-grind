class Solution {
public:
    
    int recurse(vector<int> &vec,int idx,int first,int second,int numSlots,vector<vector<vector<int>>> &dp){
        
        
        if(idx==vec.size())
            return dp[idx][first][second]=0;
        
        if(dp[idx][first][second]!=-1){
            return dp[idx][first][second];
        }
        
        int ans=0;
        for(int i=0;i<numSlots;i++){
            
            if(((1<<i)&first)==0){
                
                first^=(1<<i);
    ans=max(ans,((i+1)&vec[idx])+recurse(vec,idx+1,first,second,numSlots,dp));
                first^=(1<<i);
                
            }
            else if(((1<<i)&second)==0){
                 second^=(1<<i);
    ans=max(ans,((i+1)&vec[idx])+recurse(vec,idx+1,first,second,numSlots,dp));
                second^=(1<<i);
            }
        }
        
        return dp[idx][first][second]=ans;
    }
    
    int maximumANDSum(vector<int>& nums, int numSlots) {
        
           vector<vector<vector<int>>> dp(nums.size()+1,vector<vector<int>>(1<<(numSlots+1),vector<int> (1<<(numSlots+1),-1)) );
         
        return recurse(nums,0,0,0,numSlots,dp);
    }
};