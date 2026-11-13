class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        while(i<version1.size()||j<version2.size()){
            //find dot
            int dot1=version1.find('.',i);
            int dot2=version2.find('.',j);
            //no dot
            if(dot1==string::npos)
                dot1=version1.size();
            
            if(dot2==string::npos)
                dot2=version2.size();

            //extract rervision
             
             string part1 = (i < version1.size())
                ? version1.substr(i, dot1 - i) : "0";

            string part2 = (j < version2.size())
                ? version2.substr(j, dot2 - j) : "0";
             //string into nums
             int num1=stoi(part1);
             int num2=stoi(part2);
             //compare
             if(num1<num2)
             return -1;
             if(num1>num2)
             return 1;

             i=dot1+1;
             j=dot2+1;

        }

        return 0;
    }
};