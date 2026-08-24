class Solution {
public:
    string maskPII(string s) {
       
        if (s.find('@') != string::npos) {
            transform(s.begin(), s.end(), s.begin(), ::tolower);

            int atPos = s.find('@');
            string name = s.substr(0, atPos);
            string domain = s.substr(atPos);

            return string(1, name.front()) + "*****" +
                   string(1, name.back()) + domain;
        }


        string digits;
        for (char c : s) {
            if (isdigit(c)) {
                digits += c;
            }
        }

        int countryLen = digits.size() - 10;
        string local = "***-***-" + digits.substr(digits.size() - 4);

        if (countryLen == 0) {
            return local;
        }

        return "+" + string(countryLen, '*') + "-" + local;
    }
};