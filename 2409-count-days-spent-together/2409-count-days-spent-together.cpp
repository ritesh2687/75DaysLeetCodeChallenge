class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        auto getDayOfYear = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));
            int totalDays = day;
            for (int i = 0; i < month - 1; ++i) {
                totalDays += daysInMonths[i];
            }
            return totalDays;
        };

        int aliceArrival = getDayOfYear(arriveAlice);
        int aliceLeave = getDayOfYear(leaveAlice);
        int bobArrival = getDayOfYear(arriveBob);
        int bobLeave = getDayOfYear(leaveBob);

        int overlapStart = max(aliceArrival, bobArrival);
        int overlapEnd = min(aliceLeave, bobLeave);

        return max(0, overlapEnd - overlapStart + 1);
    }
};