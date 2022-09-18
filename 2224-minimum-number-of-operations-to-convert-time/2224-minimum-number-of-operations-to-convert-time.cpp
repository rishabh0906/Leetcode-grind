class Solution {
public:
    
    int timeConvert(string s){
        
        int h=(s[0]-'0')*10+(s[1]-'0');
        int m=(s[3]-'0')*10+(s[4]-'0');
        
        
        return h*60+m;
    }
    
    int convertTime(string current, string correct) {
        
        int cur=timeConvert(current);
        int cor=timeConvert(correct);
        
        int op=0;
        int diff=cor-cur;
        
        op+=diff/60;
        diff%=60;
        op+=diff/15;
        diff%=15;
        op+=diff/5;
        diff%=5;
        op+=diff;
        
        return op;
    }
};