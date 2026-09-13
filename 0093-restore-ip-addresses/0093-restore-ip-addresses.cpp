class Solution {
public:
    bool valid(string part) {
        if (part.empty() || part.size() > 3)
            return false;

        if (part.size() > 1 && part[0] == '0')
            return false;

        int num = stoi(part);
        return num >= 0 && num <= 255;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int n = s.size();

        for (int i = 1; i <= 3; i++) {
            for (int j = i + 1; j <= i + 3; j++) {
                for (int k = j + 1; k <= j + 3; k++) {

                    if (k >= n) continue;

                    string a = s.substr(0, i);
                    string b = s.substr(i, j - i);
                    string c = s.substr(j, k - j);
                    string d = s.substr(k);

                    if (valid(a) && valid(b) &&
                        valid(c) && valid(d)) {

                        ans.push_back(
                            a + "." + b + "." + c + "." + d
                        );
                    }
                }
            }
        }

        return ans;
    }
};