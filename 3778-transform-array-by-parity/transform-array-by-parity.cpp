class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n,0);
        for(int i : nums){
            if(i%2!=0){
                arr[--n]=1;
            }
        }return arr;
    }
};