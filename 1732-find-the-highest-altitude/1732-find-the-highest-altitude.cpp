
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> altitude(n + 1, 0);

        for (int i = 0; i < n; i++) {
            altitude[i + 1] = altitude[i] + gain[i];
        }

        int maxAltitude = 0;

        for (int i = 0; i <= n; i++) {
            maxAltitude = max(maxAltitude, altitude[i]);
        }

        return maxAltitude;
    }
};
