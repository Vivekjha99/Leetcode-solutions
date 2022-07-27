class Solution {
public:
   string dayOfTheWeek(int day, int month, int year) {
        string daysInWeek [7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}; // 1
        int DaysByMonthMod7[12] = {0,3,2,5,0,3,5,1,4,6,2,4}; // 2
        if(month < 3) year -= 1; // 3
        return daysInWeek[(year + (year/4 - year/100 + year/400) + DaysByMonthMod7[month-1] + day) % 7]; // 4
    }
};