class Solution {
public:
    int addDigits(int num) {
       while(num>9){
        int dig=0;
        while(num ){
            dig +=(num%10);
            num=num/10;
        }num=dig;
        }
        return num;
    }
};