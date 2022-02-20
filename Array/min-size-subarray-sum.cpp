class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int windowStart = 0;
        int windowSum = 0;
        int minLength = INT_MAX;
        
        for(int windowEnd = 0; windowEnd < nums.size(); windowEnd++){
            windowSum += nums[windowEnd];
            
            while(windowSum >= target){
                minLength = min(minLength, windowEnd - windowStart + 1);
                windowSum -= nums[windowStart];
                windowStart++;
            }
        }
        
        if(minLength == INT_MAX){
            return 0;
        }
        return minLength;
    }
};
