class NumArray {
   
        
        
        vector<int> bit;
        
        
        int sum(int idx){
            int ret=0;
            
            while(idx>=0){
                ret+=bit[idx];
                idx=(idx&(idx+1))-1;
            }
            
            return ret;
        }
        
        int range_sum(int l,int r){
            
            return sum(r)-sum(l-1);
            
        }
        
        void update_(int idx,int value){
            
            while(idx<bit.size()){
                bit[idx]+=value;
                
                idx=idx|(idx+1);
            }
        }
    
  public:
   vector<int> nums_dup;
    NumArray(vector<int>& nums) {
        
     bit.resize(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            nums_dup.push_back(nums[i]);
            update_(i,nums[i]);
        }
    }
    
    void update(int index, int val) {
        int delta=val-nums_dup[index];
        nums_dup[index]=val;
       
        update_(index,delta);
    }
    
    int sumRange(int left, int right) {
        return range_sum(left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */