class TrieNode{
    public:
    vector<TrieNode*>child;
    bool word;
    TrieNode(){
        child=vector<TrieNode*>(26,NULL);
        word=false;
    }
};
class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *curr=root;
        for(auto x:word){
            int idx=x-'a';
            if(!curr->child[idx])curr->child[idx]=new TrieNode();
            curr=curr->child[idx];
        }
        curr->word=true;
    }
    
    bool search(string word) {
        return searchUtilDFS(root,word);
        // TrieNode* curr=root;
        // if(word[0]=='.'){
        //     int idx=1;
        //     for(int i=0;i<26;i++){
        //         if(curr->child[i]!=NULL){
        //             TrieNode* temp=curr->child[i];
        //             while(idx<word.size() && temp->child[word[idx]-'a']){
        //                 temp=temp->child[word[idx]-'a'];
        //                 idx++;
        //             }
        //             if(idx==word.size() && temp->word)return true;
        //         }
        //     }
        //     return false;
        // }
        // else{
        //     for(auto x:word){
        //         int idx=x-'a';
        //         if(curr->child[idx]==NULL)return false;
        //         curr=curr->child[idx];
        //     }
        //     return curr->word;
        // }
    }
    bool searchUtilDFS(TrieNode *curr,string word){
        //Note : we only need to perform dfs when we encounter dot
        int length=word.size();
        int index;
        for(int i =0;i<length;i++){
            if(word[i]!='.'){  //simply traverse the TRIE
                index=word[i]-'a';
                if(curr->child[index]==NULL){
                    // that element doesnt exist
                    return false;
                }
                curr=curr->child[index];
            }else{
                //we encounter the dot operator
                //so we need to consider all possibilities that is string starting from a,b,c,d,e....so on
                bool result=false;
                int j;
                for(j =0;j<26;j++){  // to traverse string starting from a, b ,c , d and so on
                    if(curr->child[j]!=NULL)
                    result=result|searchUtilDFS(curr->child[j],word.substr(i+1)); 
                    if(result)return true;  
                }
                return false;
            }
        }
       return curr->word; // why we are returing this coz lets suppose
	   //we have " b u d d y " stored in trie and we are searching for " b u d " 
	   //it should return false correct??  so when we are at d, return curr->isend 
	   // will return false as it is not the end of the string.
	   
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */