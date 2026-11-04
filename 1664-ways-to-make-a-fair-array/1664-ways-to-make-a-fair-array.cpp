
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int evenRight = 0, oddRight = 0;
        int evenLeft = 0, oddLeft = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0)
                evenRight += nums[i];
            else
                oddRight += nums[i];
        }

        int count = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (i % 2 == 0)
                evenRight -= nums[i];
            else
                oddRight -= nums[i];

            int newEven = evenLeft + oddRight;
            int newOdd = oddLeft + evenRight;

            if (newEven == newOdd)
                count++;

      
            if (i % 2 == 0)
                evenLeft += nums[i];
            else
                oddLeft += nums[i];
        }

        return count;
    }
};
