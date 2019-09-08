// 1154. Day of the Year
// Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, return the day number of the year.

 

// Example 1:

// Input: date = "2019-01-09"
// Output: 9
// Explanation: Given date is the 9th day of the year in 2019.

// Example 2:

// Input: date = "2019-02-10"
// Output: 41

// Example 3:

// Input: date = "2003-03-01"
// Output: 60

// Example 4:

// Input: date = "2004-03-01"
// Output: 61

 

// Constraints:

//     date.length == 10
//     date[4] == date[7] == '-', and all other date[i]'s are digits
//     date represents a calendar date between Jan 1st, 1900 and Dec 31, 2019.


class Solution {
public:
    int dayOfYear(string date) {
        
        int yyyy=stoi(date);
        string m=date.substr(5,2),d=date.substr(8,2);
        int mm=stoi(m),dd=stoi(d);
        if(mm==1)   return dd;
        int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if(yyyy%400==0)
            month[1]=29;
        else if(yyyy%100==0)
            month[1]=28;
        else if(yyyy%4==0)
            month[1]=29;
        else month[1]=28;
        
        int days=0;
        for(int i=0;i<mm-1;i++){
            days+=month[i];
        }
        days+=dd;
        
        return days;
    }
};