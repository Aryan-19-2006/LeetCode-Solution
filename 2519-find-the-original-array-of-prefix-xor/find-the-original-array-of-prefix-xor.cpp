class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> res;
        int sum=0;
        for(int i : pref){
            res.push_back(i^sum);
            sum=i;
        }return res;
    }
};