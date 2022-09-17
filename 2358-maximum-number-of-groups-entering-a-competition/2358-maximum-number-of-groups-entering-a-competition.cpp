class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        
        sort(grades.begin(),grades.end());
        
        int grpSize=1;
        int ans=0;
        int i=0;
        int prev=0;
        while(i<grades.size()){
             
              int grp=grpSize;
                 int sum=0;
            int count=0;
            while(i<grades.size()&&grp-->0){
                sum+=grades[i];
                count++;
                i++;
            }
            
            if(sum>prev&&count==grpSize){
                ans++;
                prev=sum;
                
            }
            grpSize++;
        }
        
        return ans;
        
    }
};