class TrieNode{
    public:
    vector<TrieNode*>child;
    bool isEnd;
    TrieNode(){
        child=vector<TrieNode*>(26,NULL);
        isEnd=false;
    }
};
class Solution {
public:
    TrieNode *root;
    void insertWords(string s){
        TrieNode *curr=root;
        for(auto &x:s){
            int idx=x-'a';
            if(!curr->child[idx])curr->child[idx]=new TrieNode();
            curr=curr->child[idx];
        }
        curr->isEnd=true;
    }
    string repl(string s){
        TrieNode *curr=root;
        string res="";
        for(auto x:s){
            int idx=x-'a';
            if(curr->child[idx]==NULL)break;
            res+=x;
            curr=curr->child[idx];
            if(curr->isEnd)return res;
        }
        return s;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        root=new TrieNode();
        for(auto x:dictionary)insertWords(x);
        istringstream ss(sentence);
        string st="";
        string ans="";
        while(ss>>st){
            ans+=repl(st);
            ans+=' ';
        }
        ans.pop_back();
        return ans;
    }
};