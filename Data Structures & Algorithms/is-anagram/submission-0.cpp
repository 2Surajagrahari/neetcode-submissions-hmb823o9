class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n != m) return false;
        unordered_map<char,int> mp;
        for(char c:s) mp[c]++;
        for(char c:t) mp[c]--;

        for(auto it:mp){
            if(it.second != 0) return false;
        }
        return true;
    }
};
