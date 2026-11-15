
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;

        long long even = 1;
        long long odd = 0;
        long long prefixSum = 0;
        long long ans = 0;

        for (int num : arr) {
            prefixSum += num;

            if (prefixSum % 2 == 0) {
                ans += odd;
                even++;
            } 
            else {
                ans += even;
                odd++;
            }

            ans %= MOD;
        }

        return ans;
    }
};
