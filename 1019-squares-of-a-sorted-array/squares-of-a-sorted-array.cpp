class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int left = 0, right = n - 1;
        int k = n - 1;

        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                ans[k--] = nums[left] * nums[left];
                left++;
            } else {
                ans[k--] = nums[right] * nums[right];
                right--;
            }
        }

        return ans;
    }
};