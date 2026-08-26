class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        vector<int> onePositions;
        for (int index = 0; index < s.size(); index++) {
            if (s[index] == '1')
                onePositions.push_back(index);
        }

        if (onePositions.size() < k)
            return "";

        int bestStart = -1;
        int bestEnd = -1;
        int bestLength = INT_MAX;

        for (int i = 0; i + k - 1 < onePositions.size(); i++) {

            int start = onePositions[i];
            int end = onePositions[i + k - 1];
            int length = end - start + 1;
            if (length < bestLength) {
                bestLength = length;
                bestStart = start;
                bestEnd = end;
            }
            else if (length == bestLength) {

                if (s.compare(start, length, s, bestStart, bestLength) < 0) {
                    bestStart = start;
                    bestEnd = end;
                }
            }
        }

        return s.substr(bestStart, bestEnd - bestStart + 1);
    }
};