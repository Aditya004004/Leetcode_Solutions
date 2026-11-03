
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = INT_MIN;
        long long sum = 0;

        for (int num : nums) {
            maxi = max(maxi, num);
            sum += num;
        }

        return (long long)maxi * nums.size() - sum;
    }
};
