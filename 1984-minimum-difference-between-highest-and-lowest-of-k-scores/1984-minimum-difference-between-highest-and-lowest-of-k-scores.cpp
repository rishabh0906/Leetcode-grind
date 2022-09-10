class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        int ans=nums[k-1]-nums[0];
        
        int i=k;
        
        while(i<nums.size()){
            ans=min(ans,nums[i]-nums[i-k+1]);
            i++;
        }
        
        return ans;
    }
};