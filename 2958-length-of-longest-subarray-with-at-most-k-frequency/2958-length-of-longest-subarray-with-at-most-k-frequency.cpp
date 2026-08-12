class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int ,int>fre;
        int left=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            fre[nums[i]]++;
            while(fre[nums[i]]>k){
                fre[nums[left]]--;
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};