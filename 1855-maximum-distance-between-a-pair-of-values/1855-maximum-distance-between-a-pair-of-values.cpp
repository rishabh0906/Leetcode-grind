class Solution {
public:
    
    int binarySearch(vector<int> &nums,int L,int R,int x){
        
        
        int ans=-1;
        
        int l=L,r=R;
        
        while(l<=r){
            
            int mid=(r-l)/2+l;
            
            if(nums[mid]<=x){
                
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        
        return ans;
    }
    
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        
        int ans=0;
        
        for(int i=nums2.size()-1;i>=0;i--){
            
            int x=nums2[i];
            
            int l=0;
            int r=min(i,(int)nums1.size()-1);
            
            int idx=binarySearch(nums1,l,r,x);
            
            if(idx!=-1){
                
                ans=max(ans,i-idx);
            }
        }
        
        return ans;
    }
};