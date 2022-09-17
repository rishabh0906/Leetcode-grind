class TopVotedCandidate {
public:
    
    unordered_map<int,int> timeToPerson;
    vector<int> time;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
          time=times;
     
        int person=0;
        int mx=0;
        unordered_map<int,int> mp;
        for(int i=0;i<persons.size();i++){
            mp[persons[i]]++;
            if(mp[persons[i]]>mx){
                mx=mp[persons[i]];
                person=persons[i];
            }
            else if(mp[persons[i]]==mx){
                person=persons[i];
            }
            
            timeToPerson[times[i]]=person;
        }
    }
    
    int q(int t) {
        
        int l=0,r=time.size()-1;
        int ans=0;
        while(l<=r){
            
            int mid=(r-l)/2+l;
            
            if(time[mid]<=t){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
      
        return timeToPerson[time[ans]];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */