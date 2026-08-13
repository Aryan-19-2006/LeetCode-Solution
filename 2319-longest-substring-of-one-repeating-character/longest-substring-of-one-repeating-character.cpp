class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        set<int> boundaries;     
        multiset<int> lengths; 

        boundaries.insert(0);
        boundaries.insert(n);
        for (int i = 1; i < n; i++)
            if (s[i] != s[i-1]) boundaries.insert(i);

        auto it = boundaries.begin();
        int prv = *it;
        for (++it; it != boundaries.end(); ++it) {
            lengths.insert(*it - prv);
            prv = *it;
        }

        auto insertBoundary = [&](int b) {
            auto nxtIt = boundaries.lower_bound(b);
            int nxt = *nxtIt;
            auto prvIt = prev(nxtIt);
            int prev_ = *prvIt;
            lengths.erase(lengths.find(nxt - prev_));
            boundaries.insert(b);
            lengths.insert(b - prev_);
            lengths.insert(nxt - b);
        };

        auto removeBoundary = [&](int b) {
            auto it = boundaries.find(b);
            auto nxtIt = next(it);
            int nxt = *nxtIt;
            auto prvIt = prev(it);
            int prev_ = *prvIt;
            lengths.erase(lengths.find(b - prev_));
            lengths.erase(lengths.find(nxt - b));
            boundaries.erase(it);
            lengths.insert(nxt - prev_);
        };

        auto toggle = [&](int pos, bool wasB, bool isB) {
            if (wasB && !isB) removeBoundary(pos);
            else if (!wasB && isB) insertBoundary(pos);
        };

        int q = queryIndices.size();
        vector<int> ans(q);
        for (int qi = 0; qi < q; qi++) {
            int idx = queryIndices[qi];
            char c = queryCharacters[qi];
            char oldChar = s[idx];

            if (oldChar != c) {
                if (idx >= 1) {
                    bool wasB = (oldChar != s[idx-1]);
                    bool isB  = (c != s[idx-1]);
                    toggle(idx, wasB, isB);
                }
                if (idx + 1 <= n - 1) {
                    bool wasB = (s[idx+1] != oldChar);
                    bool isB  = (s[idx+1] != c);
                    toggle(idx + 1, wasB, isB);
                }
                s[idx] = c;
            }
            ans[qi] = *lengths.rbegin();
        }
        return ans;
    }
};