class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size(),oi=0,ni=0;
        k%=(m*n);
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                oi=i*n +j;

                ni= (oi +k) % (m*n);
                int newRow = ni / n;
                int newCol = ni % n;
                ans[newRow][newCol]=grid[i][j];
            }
        }return ans;
    }
};