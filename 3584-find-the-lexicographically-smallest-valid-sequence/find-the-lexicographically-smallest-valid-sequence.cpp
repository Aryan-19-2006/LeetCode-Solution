class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();

       
        vector<int> sufFeasible(m + 1);
        sufFeasible[m] = n;
        int ptr = n - 1;
        for (int j = m - 1; j >= 0; j--) {
            while (ptr >= 0 && word1[ptr] != word2[j]) ptr--;
            sufFeasible[j] = ptr; 
            ptr--;
        }

        vector<int> result;
        result.reserve(m);
        int i1 = 0, i2 = 0;
        bool mismatchUsed = false;

        while (i1 < n && i2 < m) {
            if (word1[i1] == word2[i2]) {
                result.push_back(i1);
                i1++; i2++;
            } else if (!mismatchUsed && i1 + 1 <= sufFeasible[i2 + 1]) {
               
                result.push_back(i1);
                mismatchUsed = true;
                i1++; i2++;
            } else {
                i1++; 
            }
        }

        if (i2 < m) return {};
        return result;
    }
};