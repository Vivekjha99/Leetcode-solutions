class Solution {
public:
    bool isPalindrome(int x) {
      if(x<0)return false;
        string s=to_string(x);
        string ns=s;
        reverse(s.begin(),s.end());
        if(ns.compare(s)==0)return true;
        else return false;
        
    }
};