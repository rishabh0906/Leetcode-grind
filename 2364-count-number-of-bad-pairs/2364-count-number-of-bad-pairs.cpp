class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        
        int n=nums.size();
        
        long long total=(n*(n-1LL))/2;
        
        unordered_map<int,int> mp;
        long long count=0;
        for(int i=0;i<n;i++){
        
            if(mp.find(nums[i]-i)!=mp.end()){
                     count+=mp[nums[i]-i];      
            }
          
            mp[nums[i]-i]++;
            
            
        }
        
        
        return total-count;
        
    }
};