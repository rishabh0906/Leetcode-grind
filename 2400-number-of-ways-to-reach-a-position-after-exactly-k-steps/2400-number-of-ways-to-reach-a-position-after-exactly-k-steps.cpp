class Solution {
public:
    
    int binomialCoeff(int n, int k)
{
    long long C[n + 1][k + 1];
    int i, j;
          int mod =(int) 1e9+7;
    
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i, k); j++) {
          
            if (j == 0 || j == i)
                C[i][j] = 1LL;
 
            
            else
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j])%mod;
        }
    }
 
    return C[n][k];
}
    int numberOfWays(int startPos, int endPos, int k) {
        
        int y=(endPos-startPos+k);
        
        if(y%2!=0)
            return 0;
        
        y=y/2;
        
        if(y>k)
            return 0;
        
        return binomialCoeff(k,y);
        
        
        
        
    }
};