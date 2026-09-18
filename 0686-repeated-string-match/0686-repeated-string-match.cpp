class Solution {
public:
    bool contains(string &s, string &b){
        int n=s.size() , m=b.size();
        for(int i=0;i<=n-m;i++){
            int j=0;
            while(j<m && s[i+j]==b[j])
            j++;
            if(j==m)
                return true;
            }
            return false;
        }

    int repeatedStringMatch(string a, string b) {
        string s="";
        int count =0;
        while(s.size()<=a.size()+b.size()){
            s+=a;
            count++;
            if(contains(s,b))
            return count;
        }
        return -1;
    }
};