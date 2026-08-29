class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>sc;
        unordered_map<char,int>st;
        if(s.length()!=t.length()) return false;
        for(int i=0;i<s.length();i++){
            sc[s[i]]++;
            st[t[i]]++;
        }
        if(sc == st) return true;
        return false;
    }
};