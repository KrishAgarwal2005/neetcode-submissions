class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>mp;
        int l=0;
        int res=0;
        for(int r=0;r<s.size();r++){
        while(mp.find(s[r])!=mp.end()){
            mp.erase(s[l]);
            l++;
        }
        mp.insert(s[r]);
        res=max(r-l+1,res);
        }
        return res;
    }
};
