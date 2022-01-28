class Trie {
    private:
    Trie* child[26]={};
    bool end=false;
public:
    Trie() {
       
    }
    void insert(string word) {
        Trie* node=this;
        for(auto x:word){
            if(node->child[x-'a']==NULL)node->child[x-'a']=new Trie();
            node=node->child[x-'a'];
        }
        node->end=true;
    }
    
    bool search(string word) {
        Trie* node=this;
        for(auto x:word){
            if(!node->child[x-'a'])return false;
            node=node->child[x-'a'];
        }
        return node->end;
    }
    bool startsWith(string prefix) {
        Trie* node=this;
        for(auto x:prefix){
            if(!node->child[x-'a'])return false;
            node=node->child[x-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */