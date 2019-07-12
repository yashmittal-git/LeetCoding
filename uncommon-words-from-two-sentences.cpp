// 884. Uncommon Words from Two Sentences
// We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)

// A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

// Return a list of all uncommon words. 

// You may return the list in any order.

 

// Example 1:

// Input: A = "this apple is sweet", B = "this apple is sour"
// Output: ["sweet","sour"]
// Example 2:

// Input: A = "apple apple", B = "banana"
// Output: ["banana"]
 

// Note:

// 0 <= A.length <= 200
// 0 <= B.length <= 200
// A and B both contain only spaces and lowercase letters.


class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        map<string,int> mymap;
        vector<string> ans;
        for(int i=0;i<A.size();i++) {
            string word;
            while(A[i]!=' '&&i<A.size())  {
                word.push_back(A[i]);
                i++;
            }
            mymap[word]++;
        }
        for(int i=0;i<B.size();i++) {
            string word;
            while(B[i]!=' '&&i<B.size())  {
                word.push_back(B[i]);
                i++;
            }
            mymap[word]++;
        }
        for(auto it=mymap.begin();it!=mymap.end();it++){
            if(it->second==1)   ans.push_back(it->first);
        }
        return ans;
    }
};