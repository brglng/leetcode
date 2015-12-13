#include <iostream>
#include <deque>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        deque<char> chardeque;
        unordered_set<char> charset;
        int maxLen = 0;
        
        for (string::iterator it = s.begin(); it < s.end(); ++it) {
            char curChar = *it;
            if (charset.find(curChar) == charset.end()) {
                chardeque.push_back(curChar);
                charset.insert(curChar);
            } else {
                if (charset.size() > maxLen) {
                    maxLen = charset.size();
                }
                
                char c = 0;
                while (c != curChar && chardeque.size() > 0 && charset.size() > 0) {
                    c = chardeque.front();
                    chardeque.pop_front();
                    charset.erase(c);
                } 
                chardeque.push_back(curChar);
                charset.insert(curChar);
            }
        }
        
        if (charset.size() > maxLen) {
            maxLen = charset.size();
        }
        
        return maxLen;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    string s;

    while (true) {
        getline(cin, s);
        if (!cin) {
            break;
        }
        cout << sol.lengthOfLongestSubstring(s) << endl;
    }

    return 0;
}
