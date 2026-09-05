class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map <int,int> mpp;
        vector<int> ans;
        for(auto i : nums){
            mpp[i]++;
            if(mpp[i]==2)
            ans.push_back(i);
        }
        return ans;
    }
};