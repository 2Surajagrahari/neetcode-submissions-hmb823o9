class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto const& [key, val] : mp){
            if(val > 1){
                return true;
            }
        }
        return false;
    }
};