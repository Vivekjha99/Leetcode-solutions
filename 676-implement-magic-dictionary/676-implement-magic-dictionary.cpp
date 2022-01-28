class MagicDictionary {

  	class trienode{
      public:
          vector<trienode *> alphabets = vector<trienode *> (26, nullptr);
          bool is_end=false;
  };
  trienode *root;
  
  bool search(trienode *cur,  string &word, int index, bool flag){
      if(index == word.length()){
          if(flag && cur->is_end) return true;
          return false;
      }   
      int right = word[index]-'a'; 
      for(int i=0;i<26;i++){
          if(cur->alphabets[i]){
              if(right!=i && !flag){
                  if(search(cur->alphabets[i], word, index+1,true)) return true;
              }else{
                  if(right==i && search(cur->alphabets[i], word, index+1,flag)) return true;
              }
          }
      }
      return false;
      }
public:
  MagicDictionary() {
      root = new trienode();
  }
  
  /** Build a dictionary through a list of words */
  void buildDict(vector<string> dict) {
      trienode *start;
      for(auto word:dict){
          start = root; 
          for(auto c:word){
              if(start->alphabets[c - 'a']){
                  start = start->alphabets[c - 'a'];
              }else{
                  start->alphabets[c - 'a'] = new trienode();
                  start = start->alphabets[c - 'a'];
              }
          }
          start-> is_end = true;
      }
  }
  
  /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
  bool search(string word) {
      return search(root, word, 0, false);
  }
};