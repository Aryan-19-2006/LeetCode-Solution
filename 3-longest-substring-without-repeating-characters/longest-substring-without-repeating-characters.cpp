class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;

        int i = 0, maxi = 0;

        for (int j = 0; j < s.size(); j++) {

            if (mpp.find(s[j]) != mpp.end()) {
                i = max(i, mpp[s[j]] + 1);
            }

            mpp[s[j]] = j;

            maxi = max(maxi, j - i + 1);
        }

        return maxi;
    }
};