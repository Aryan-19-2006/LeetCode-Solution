class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string alpha="";
        int sum=0;
        for(int i =0; i< words.size();i++){
            sum=0;
            for(char j : words[i]){
                sum+=weights[(j-97)];
            }
           alpha += char('z' - (sum % 26));
        }return alpha;
    }
};