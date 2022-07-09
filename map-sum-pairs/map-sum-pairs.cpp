class MapSum {
    struct Trie{
    vector<Trie*>child;
    int vals;
        Trie(){
            child=vector<Trie*>(26,NULL);
            vals=0;
        }
    };
public:
    Trie*  root=new Trie();
    unordered_map<string,int>mp;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        Trie* curr=root;
        for(auto x:key){
            int idx=x-'a';
            if(curr->child[idx]==NULL){
                curr->child[idx]=new Trie();
            }
            curr=curr->child[idx];
            curr->vals+=val-mp[key];
        }
        mp[key]=val;
    }
    
    int sum(string prefix) {
        Trie* curr=root;
        for(auto x:prefix){
            int idx=x-'a';
            if(!curr->child[idx])return 0;
            curr=curr->child[idx];
        }
        return curr->vals;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */