class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int answer = n * 2;

        sort(reservedSeats.begin(), reservedSeats.end());

        for (int i = 0; i < reservedSeats.size(); i++) {
            int currentRow = reservedSeats[i][0];

            bool leftBlockAvailable = true;
            bool middleBlockAvailable = true;
            bool rightBlockAvailable = true;

            while (i < reservedSeats.size() &&
                   reservedSeats[i][0] == currentRow) {

                int seat = reservedSeats[i][1];

                if (seat >= 2 && seat <= 5) {
                    leftBlockAvailable = false;
                }

                if (seat >= 4 && seat <= 7) {
                    middleBlockAvailable = false;
                }

                if (seat >= 6 && seat <= 9) {
                    rightBlockAvailable = false;
                }

                i++;
            }

            if (leftBlockAvailable && rightBlockAvailable) {
            } else if (leftBlockAvailable || middleBlockAvailable ||
                       rightBlockAvailable) {
                answer--;
            } else {
                answer -= 2;
            }
            i--;
        }

        return answer;
    }
};