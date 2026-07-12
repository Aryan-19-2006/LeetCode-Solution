class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mpp;
        int ans=-1;
        for(auto i : arr){
            mpp[i]++;
        }
        for(auto i : mpp){
            if(i.first == i.second){
                ans = max(ans,i.first);
            }
        }
        
        return ans;;
    }
};