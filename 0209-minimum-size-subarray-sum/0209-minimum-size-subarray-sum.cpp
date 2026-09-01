class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
            int n=nums.size();
            int left =0;
            long long sum =0;
            int minl =INT_MAX;
            for(int right=0;right<n;right++){
                sum +=nums[right];
            while(sum>=target){
                minl =min(minl,right-left+1);
                sum -=nums[left];
                left++;
            }
            }
            return (minl==INT_MAX)?0:minl;
    }
};