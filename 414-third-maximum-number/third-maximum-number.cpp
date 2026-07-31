class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long t1 = LLONG_MIN, t2 = LLONG_MIN, t3 = LLONG_MIN;

        for (int x : nums) {
            if (x == t1 || x == t2 || x == t3)
                continue;

            if (x > t1) {
                t3 = t2;
                t2 = t1;
                t1 = x;
            } else if (x > t2) {
                t3 = t2;
                t2 = x;
            } else if (x > t3) {
                t3 = x;
            }
        }

        return (t3 == LLONG_MIN) ? t1 : t3;
    }
};