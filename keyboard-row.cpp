// 500. Keyboard Row
// Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.

 



 
// Example:

// Input: ["Hello", "Alaska", "Dad", "Peace"]
// Output: ["Alaska", "Dad"]
 

// Note:

// You may use one character in the keyboard more than once.
// You may assume the input string will only contain letters of alphabet.


class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> keyboard={"qwertyuiopQWERTYUIOP","asdfghjklASDFGHJKL","zxcvbnmZXCVBNM"};
        vector<string> ans;
        int inSet,i,j;
        for(i=0;i<words.size();i++)
        {
            if(keyboard[0].find(words[i][0])!=-1)    inSet=0;
            else    if(keyboard[1].find(words[i][0])!=-1)    inSet=1;
            else    if(keyboard[2].find(words[i][0])!=-1)    inSet=2;
            
            for(j=0;j<words[i].size();j++)
            {   if(keyboard[inSet].find(words[i][j])==-1)
                break;                
            }
            if(j==words[i].size())
                ans.push_back(words[i]);
        }
        return ans;
    }
};