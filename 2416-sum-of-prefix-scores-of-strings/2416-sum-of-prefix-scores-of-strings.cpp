class Solution {
public:
    
    struct Trie{
         
         private:
          
          int count;
        public:
        vector<Trie *> child; 
         Trie(){
             child.resize(26);
             count=0;
         }
        
        void IncrementCount(){
            count++;
        }
        
        int getCount(){
            return count;
        }
        
    
        
        
        
    };
    
    void addWord(Trie *root,string word ){
        
        Trie *curr=root;
        for(int i=0;i<word.size();i++ ){
            
            if(curr->child[word[i]-'a']){
                
                
            }
            else{
                curr->child[word[i]-'a']=new Trie();
            }
           
            curr=curr->child[word[i]-'a'];
             curr->IncrementCount();
           
        }
    }
    
    int search(Trie *root,string word){
        int score=0;
        Trie *curr=root;
        for(int i=0;i<word.size();i++){
                
            curr=curr->child[word[i]-'a'];
            score+=curr->getCount();
            
        }
        
        return score;
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
       
        Trie *root=new Trie();
        
        for(int i=0;i<words.size();i++){
            addWord(root,words[i]);
        }
        vector<int> ans(words.size());
        
        for(int i=0;i<words.size();i++){
            
            int as=search(root,words[i]);
            ans[i]=as;
        }
        
        return ans;
        
        
    }
};