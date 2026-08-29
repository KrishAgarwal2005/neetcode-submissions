class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>num;
        for(int n:nums){
            if(num.count(n)) return true;
            num.insert(n);
        }
       return false;
    }
};