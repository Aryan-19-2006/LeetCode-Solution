class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int n=s.size(),c=0;
        int i =n-1;
        while((i>=0) && s[i] == ' '){
            i--;}
        while(i>-1 && (s[i]!= ' ')){
            i--;
            c++;
        }return c;
    }
};