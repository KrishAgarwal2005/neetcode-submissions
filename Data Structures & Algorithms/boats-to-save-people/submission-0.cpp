class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats=0;
        sort(people.begin(),people.end());
        int l=0;int r=people.size()-1;
       
        while(l<=r){
            int remain=limit-people[r];
            r--;
            boats++;
            if(l<=r && remain>=people[l]) l++;
        }
        return boats;
    }
};