class Solution {
public:
    int longestContinuousSubstring(string s) {
        
        char ch='#';
        int ans=0;
        int count=0;
        for(int i=0;i<s.size();i++){
            
            if(ch=='#'||s[i]-ch==1){
                count++;
                ch=s[i];
            }
            else{
                ans=max(ans,count);
                count=1;
                ch=s[i];
            }
        }
        ans=max(ans,count);
        
        return ans;
        
    }
};