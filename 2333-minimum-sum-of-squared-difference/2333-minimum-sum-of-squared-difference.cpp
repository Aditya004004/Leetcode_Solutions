
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL * k1 + k2;

        vector<int> diff(n);
        long long total = 0;
        int high = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            high = max(high, diff[i]);
        }

        if (k >= total) return 0;

        int low = 0;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long need = 0;

            for (int d : diff) {
                if (d > mid) {
                    need += d - mid;
                }
            }

            if (need <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        int x = low;
        long long used = 0;
        long long ans = 0;
        long long countAtLeastX = 0;

        for (int d : diff) {
            int reduced = min(d, x);

            used += d - reduced;
            ans += 1LL * reduced * reduced;

            if (d >= x) {
                countAtLeastX++;
            }
        }

        long long rem = k - used;

        if (x > 0) {
            ans -= rem * (2LL * x - 1);
        }

        return ans;
    }
};
