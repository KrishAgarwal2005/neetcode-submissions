class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>count;
        for(int num:nums){
        count[num]++;
        }  
        vector<vector<int>>bucket(nums.size()+1);
        for(auto&it:count){
            bucket[it.second].push_back(it.first);
        }
        vector<int>ans;
        for(int i=nums.size();i>=0;i--){
            for(int num:bucket[i]){
                ans.push_back(num);
                if(ans.size()==k)
                return ans;
            }
        }
        return ans;
         }
};
