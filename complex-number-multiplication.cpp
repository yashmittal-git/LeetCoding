// 537. Complex Number Multiplication
//  Given two strings representing two complex numbers.

// You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

// Example 1:

// Input: "1+1i", "1+1i"
// Output: "0+2i"
// Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.

// Example 2:

// Input: "1+-1i", "1+-1i"
// Output: "0+-2i"
// Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.

// Note:

//     The input strings will not have extra blank.
//     The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.


class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        string x1=a.substr(0,a.find('+'));
        string x2=b.substr(0,b.find('+'));
        string y1=a.substr(a.find('+')+1);
        y1=y1.substr(0,y1.size()-1);
        string y2=b.substr(b.find('+')+1);
        y2=y2.substr(0,y2.size()-1);
        int a1=stoi(x1),b1=stoi(y1),c=stoi(x2),d=stoi(y2);
        int x=(a1*c-b1*d),y=(b1*c+a1*d);
        return to_string(x)+'+'+to_string(y)+'i';
    }
    // (x1+iy1)(x2+iy2)=(x1x2-y1y2)+i(y1x2+x1y2)
};