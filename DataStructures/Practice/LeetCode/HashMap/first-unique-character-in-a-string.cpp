class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        int i;
        for(i=0;i<s.length();i++){
            if(mp[s[i]]==1){
                break;
            }
        }
        if(i>=s.length())return -1;
        else return i;
    }
};
