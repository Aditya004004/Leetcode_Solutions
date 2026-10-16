class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>st;
        for(int x:nums){
            st.insert(x);
        }
        int ans=1;
        while(st.count(ans)){
            ans++;
        }
        return ans;
    }
};