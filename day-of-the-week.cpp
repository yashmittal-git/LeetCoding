// 1185. Day of the Week
// Given a date, return the corresponding day of the week for that date.

// The input is given as three integers representing the day, month and year respectively.

// Return the answer as one of the following values {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.

 

// Example 1:

// Input: day = 31, month = 8, year = 2019
// Output: "Saturday"

// Example 2:

// Input: day = 18, month = 7, year = 1999
// Output: "Sunday"

// Example 3:

// Input: day = 15, month = 8, year = 1993
// Output: "Sunday"

 

// Constraints:

//     The given dates are valid dates between the years 1971 and 2100.


class Solution {
    bool isLeapYear(int year){
        if(year%400==0||(year%4==0&&year%100!=0))
            return 1;
        return 0;
    }
public:
    string dayOfTheWeek(int day, int month, int year) {
        string days[]={"Thursday","Friday","Saturday","Sunday","Monday","Tuesday","Wednesday"};
        int months[]={31,28,31,30,31,30,31,31,30,31,30,31};
        int d=0;
        for(int i=1971;i<year;i++){
            if(isLeapYear(i))
                d+=366;
            else d+=365;
        }
        if(isLeapYear(year))
            months[1]=29;
        for(int i=1;i<month;i++){
            d+=months[i-1];
        }
        d+=day;
        return days[d%7];
    }
};