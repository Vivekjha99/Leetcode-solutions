struct trienode{
    trienode* child[26];
    bool end=false;
};
class WordDictionary {
public:
    WordDictionary() {
       root=new trienode(); 
    }
    
    void addWord(string word) {
        trienode* node=root;
        for(auto ch:word){
            if(!node->child[ch-'a'])node->child[ch-'a']=new trienode();
            node=node->child[ch-'a'];
        }
        node->end=true;
    }
    bool search(string word) {
     return helper(word,root);   
    }
    private:
    trienode* root;
    bool helper(string word,trienode* curr){
        for(int i=0;i<word.size();i++){
            if(word[i]!='.'){
                if(curr->child[word[i]-'a']==NULL)return false;
                curr=curr->child[word[i]-'a'];
            }
            else{
                bool found =false;
                for(int j=0;j<26;j++){
                    if(curr->child[j])found|=helper(word.substr(i+1),curr->child[j]);
                    if(found)return true;
                }
                return false;
            }
        }
        return curr->end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */