class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(nums);

        
        for (int len = 2; len <= n; len++) {
            for (int i = n - len; i >= 0; i--) {
                int j = i + len - 1;

                dp[j] = max(
                    nums[i] - dp[j],     
                    nums[j] - dp[j - 1]   
                );
            }
        }

        return dp[n - 1] >= 0;
    }
};