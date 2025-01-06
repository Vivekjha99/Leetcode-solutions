class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        string res="";
        for(char ch:s){
            if(ch!=']')st.push(ch);
            else{
                string temp="";
                while(!st.empty() && st.top()!='['){
                    temp+=st.top();
                    st.pop();
                }
                reverse(temp.begin(),temp.end());
                st.pop();
                //for digits
                string num="";
                while(!st.empty() && isdigit(st.top())){
                    num.push_back(st.top());
                    st.pop();
                }
                reverse(num.begin(),num.end());
                int number=stoi(num);
                for(int i=0;i<number;i++){
                    for(char ch1:temp)st.push(ch1);
                }
            }
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};