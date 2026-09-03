class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;

        // Smallest odd number find karo
        for (int x : nums1) {
            if (x % 2 == 1) {
                minOdd = min(minOdd, x);
            }
        }

        // Agar koi odd nahi hai,
        // saare numbers already even hain
        if (minOdd == INT_MAX)
            return true;

        // Agar koi even number smallest odd se chhota hai,
        // to us even ko odd nahi bana sakte.
        for (int x : nums1) {
            if (x % 2 == 0 && x < minOdd) {
                return false;
            }
        }

        return true;
    }
};
