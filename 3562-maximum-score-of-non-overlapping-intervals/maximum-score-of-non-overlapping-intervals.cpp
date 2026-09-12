struct Data {
    int l, r, w, id;

    bool operator<(const Data& o) const {
        return r < o.r;
    }
};

using ll = long long;

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        const int INF = INT_MAX;

        vector<Data> A(n);

        for (int i = 0; i < n; ++i) {
            A[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        sort(A.begin(), A.end());

        vector<array<ll, 5>> dp(n + 1);
        vector<array<array<int, 4>, 5>> idx(n + 1);

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= 4; ++j) {
                idx[i][j].fill(INF);
            }
        }

        for (int i = 0; i < n; ++i) {
            auto [l, r, w, id] = A[i];

            // Number of intervals before i with end < l.
            int k = lower_bound(
                A.begin(),
                A.begin() + i,
                l,
                [](const Data& d, int x) {
                    return d.r < x;
                }
            ) - A.begin();

            for (int j = 1; j <= 4; ++j) {
                ll skip = dp[i][j];
                ll take = dp[k][j - 1] + w;

                if (skip > take) {
                    dp[i + 1][j] = skip;
                    idx[i + 1][j] = idx[i][j];
                } 
                else {
                    dp[i + 1][j] = take;

                    auto cur = idx[k][j - 1];

                    // Insert id into the sorted index list.
                    cur[j - 1] = id;

                    for (int p = j - 2; p >= 0; --p) {
                        if (cur[p] < id)
                            break;
                        swap(cur[p], cur[p + 1]);
                    }

                    if (skip == take)
                        idx[i + 1][j] = min(idx[i][j], cur);
                    else
                        idx[i + 1][j] = cur;
                }
            }
        }

        vector<int> ans;

        for (int i = 0; i < 4; ++i) {
            if (idx[n][4][i] == INF)
                break;
            ans.push_back(idx[n][4][i]);
        }

        return ans;
    }
};
