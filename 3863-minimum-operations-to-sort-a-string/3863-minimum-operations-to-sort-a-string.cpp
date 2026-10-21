class Solution {
public:
    int minOperations(string s) {
       int n = s.size();
        if (std::is_sorted(s.begin(), s.end())) {
            return 0;
        }
        if (n == 2) {
            return -1;
        }
        char min_c = 'z', max_c = 'a';
        int count_min = 0, count_max = 0;
        for (char c : s) {
            if (c < min_c) {
                min_c = c;
                count_min = 1;
            } else if (c == min_c) {
                count_min++;
            }
            if (c > max_c) {
                max_c = c;
                count_max = 1;
            } else if (c == max_c) {
                count_max++;
            }
        }
        if (s[0] == min_c || s[n - 1] == max_c) {
            return 1;
        }
        if (s[0] == max_c && count_max == 1 && s[n - 1] == min_c && count_min == 1) {
            return 3;
        }
        return 2;
    }
};