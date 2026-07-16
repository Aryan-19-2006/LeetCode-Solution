
class Solution{
public:
    long long gcdSum(vector<int>& nums){
        int n=nums.size(),mx=0;long long sum=0;
        vector<int> prefixGcd(n);
        for(int i=0;i<n;i++){
            mx =max(mx,nums[i]);
            prefixGcd[i]= gcd(mx,nums[i]);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int i=0,j=n-1;
        while(i<j){
            sum += gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }return sum;
    }
};
//Direct Method
// class Solution {
// public:
//     long long gcdSum(vector<int>& nums) {
//         int n=nums.size();
//         sort(nums.begin(),nums.end());
//         int j=n-1,i=0;
//         long long sum=0;
//         while(i<j){
//             sum += gcd(nums[i],nums[j]);
//             i++;
//             j--;
//         }return sum;
//     }
// };
