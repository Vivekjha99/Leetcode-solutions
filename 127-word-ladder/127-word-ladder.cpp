class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        int n=wordList.size();
        for(int i=0;i<n;i++){
            st.insert(wordList[i]);
        }
        if(st.find(endWord)==st.end())
            return 0;
        queue<string>q;
        q.push(beginWord);
        int depth=0;
        while(!q.empty()){
            depth+=1;
            int siz=q.size();
            while(siz--){
                string curr=q.front();
                q.pop();
                for(int i=0;i<curr.length();i++){
                    string temp=curr;
                    for(char ch='a' ;ch<='z';ch++){
                        temp[i]=ch;
                        if(temp.compare(endWord)==0){
                            //we have found the word
                            return depth +1;
                        }
                        if(temp.compare(curr)==0){
                            //same word skip this
                            continue;
                        }
                        if(st.find(temp)!=st.end()){
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};