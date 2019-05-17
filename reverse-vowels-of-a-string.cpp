// 345. Reverse Vowels of a String
// Write a function that takes a string as input and reverse only the vowels of a string.

// Example 1:

// Input: "hello"
// Output: "holle"
// Example 2:

// Input: "leetcode"
// Output: "leotcede"
// Note:
// The vowels does not include the letter "y".



class Solution {
public:
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(isVowel(s[i]))
            {
                if(isVowel(s[j]))
                {
                    char c;
                    c=s[i];
                    s[i]=s[j];
                    s[j]=c;
                    i++;
                }
                j--;
            }
            else i++;
        }
        return s;
            
    }
    bool isVowel(char l)
    {    if(l=='a'||l=='a'-32||l=='e'||l=='e'-32||l=='i'||l=='i'-32||l=='o'||l=='o'-32||l=='u'||l=='u'-32)
            return 1;
        return 0;
    }
};