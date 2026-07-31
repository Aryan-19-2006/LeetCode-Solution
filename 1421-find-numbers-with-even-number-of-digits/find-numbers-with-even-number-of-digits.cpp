class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int mx=0,count=0,d=0;
        for(auto i:nums){
            count=0;
            while(i>0)
            {
                d=i%10;
                count++;
                i/=10;
            }
            if(count%2==0){
                mx++;
            }
        }return mx;
    }
};