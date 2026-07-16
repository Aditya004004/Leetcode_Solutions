class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size()>magazine.size()) return false;
        unordered_map<char,int>mp;
        for(char c:ransomNote){
            mp[c]++;
        }
        for(char c:magazine){
            mp[c]--;
        }
        for(auto it:mp){
            if(it.second>0) return false;
        }
        return true;
    }
};