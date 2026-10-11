
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                sum += nums[i - 1] * nums[i - 1];

                int other = n / i;

                if (other != i) {
                    sum += nums[other - 1] * nums[other - 1];
                }
            }
        }

        return sum;
    }
};
