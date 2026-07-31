class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int mx=0;
        
        for(auto i:accounts){
            int sum=0;
            for(int j=0;j<i.size();j++){
                sum+= i[j];
               
            }  mx=max(mx,sum);
           
        }return mx;
    }
};