class Solution {
public:
    bool isVowel(char c){
        if(c=='a' ||c=='A' || c=='E' || c=='e'|| c=='I'|| c=='i'|| c=='O'|| c=='o'|| c=='u'|| c=='U')return true;
        return false;
    }
    string reverseVowels(string s) {
        vector<int>nums;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(isVowel(s[i]))nums.push_back(i);
        }
        int i=0,j=nums.size()-1;
        while(i<j){
            swap(s[nums[i]],s[nums[j]]);
            i++;
            j--;
        }
        return s;
    }
};