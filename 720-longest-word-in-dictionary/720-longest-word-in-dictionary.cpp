struct trie{
    trie* child[26]={};
    bool end=false;
};

class Solution {
public:
    string ans="";
    void insert(string word,trie* root){
        int n=word.size();
        trie* curr=root;
        string s="";
        for(int i=0;i<n;i++){
            if(i==n-1)s+=word[i];
            int idx=word[i]-'a';
            if(curr->child[idx]==NULL){
                if(i!=n-1){
                    //if it is not th last character it is not going to contribute
                    break;
                }
                curr->child[idx]=new trie();
            }
            else s+=word[i];
            curr=curr->child[idx];
        }
        if(s.size()>ans.size())ans=s;
        else if(s.size()==ans.size() && s<ans)ans=s;
        curr->end=true;
    }
       
    string longestWord(vector<string>& words) {
            sort(words.begin(),words.end());
            trie* root=new trie();
        int n=words.size();
            for(int i=0;i<n;i++){
                if(i<n-1 && words[i]==words[i+1])continue;
                insert(words[i],root);
            }
        return ans;
    }
};