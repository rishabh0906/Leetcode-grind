class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        
        vector<int> bit_count(32);
        
        int start=0;
        int end=0;
        int ans=0;
        int n=nums.size();
        while(end<n){
            
            for(int i=0;i<32;i++){
                
                if(((1<<i)&nums[end])!=0)
                    bit_count[i]++;
            }
            
          
            int max_bit=*max_element(bit_count.begin(),bit_count.end());
            
            while(max_bit>1&&start<end){
                
                for(int i=0;i<32;i++){
                
                if(((1<<i)&nums[start])!=0)
                    bit_count[i]--;
            }
                max_bit=*max_element(bit_count.begin(),bit_count.end());
                start++;
            }
            
            ans=max(ans,end-start+1);
            end++;
        }
        
        return ans;
      
        
    }
};