class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                int depth = 0;

                for (int j = 0; j <= i; j++) {
                    if (s[j] == '(')
                        depth++;
                    else if (s[j] == ')')
                        depth--;
                }

                ans = max(ans, depth);
            }
        }

        return ans;
    }
};