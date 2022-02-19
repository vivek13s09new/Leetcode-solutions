class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int windowStart = 0;
        int windowSum = 0;
        int maxSum = INT_MIN;
        
        for(int windowEnd = 0; windowEnd < nums.size(); windowEnd++){
            windowSum += nums[windowEnd];
            
            if(windowEnd >= k - 1){
                maxSum = max(windowSum, maxSum);
                windowSum -= nums[windowStart];
                windowStart++;
            }
        }
        
        double maxAvg = (double)maxSum / k;
        return maxAvg;
    }
};
