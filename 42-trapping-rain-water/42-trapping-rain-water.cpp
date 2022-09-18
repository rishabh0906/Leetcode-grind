class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        if(n==0)
        {
            return 0;
        }
        int pref[n];
        pref[0]=height[0];
        for(int i=1;i<n;i++)
        {
            pref[i]=max(pref[i-1],height[i]);
        }
        int suff[n];
        suff[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suff[i]=max(suff[i+1],height[i]);
        }
        int res=0;
        for(int i=1;i<n-1;i++)
        {
            res+=min(pref[i],suff[i])-height[i];
        }
        return res;
    }
};