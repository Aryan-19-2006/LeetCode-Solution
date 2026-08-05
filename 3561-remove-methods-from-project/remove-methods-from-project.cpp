class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for (auto e : invocations) {
            adj[e[0]].push_back(e[1]);
        }

        // Find all suspicious methods
        vector<bool> suspicious(n, false);

        function<void(int)> dfs = [&](int u) {
            suspicious[u] = true;
            for (int v : adj[u]) {
                if (!suspicious[v])
                    dfs(v);
            }
        };

        dfs(k);

        // Check if any non-suspicious method calls a suspicious one
        for (auto &e : invocations) {
            int u = e[0], v = e[1];
            if (!suspicious[u] && suspicious[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Return all non-suspicious methods
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};