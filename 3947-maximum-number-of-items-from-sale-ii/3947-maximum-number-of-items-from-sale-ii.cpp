
class Solution {
public:
    long long maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> freq(n + 1, 0);

        int minPrice = INT_MAX;

        for (auto& item : items) {
            freq[item[0]]++;
            minPrice = min(minPrice, item[1]);
        }

        vector<int> gain(n + 1, 0);

        for (int f = 1; f <= n; f++) {
            for (int multiple = f; multiple <= n; multiple += f) {
                gain[f] += freq[multiple];
            }

            gain[f]--; 
        }

        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        long long ans = 0;
        long long remaining = budget;

        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            if (2LL * minPrice <= price)
                break;

            if (gain[factor] <= 0)
                continue;

            long long canBuy = min(
                (long long)gain[factor],
                remaining / price
            );

            ans += 2 * canBuy;
            remaining -= canBuy * price;
        }

        ans += remaining / minPrice;

        return ans;
    }
};
