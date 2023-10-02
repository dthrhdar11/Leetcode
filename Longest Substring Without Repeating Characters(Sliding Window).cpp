//Given a string s, find the length of the longest substring without repeating characters.
//Sliding Window(Two pointer Variation)
#include<iostream>
#include<set>
using namespace std;
int lengthOfLongestSubstring(string s) {
        int windowStart = 0, windowEnd = 0, strlength = 0;
        set<char> charset;
        for(windowEnd=0;windowEnd < s.length();windowEnd++){
            if(charset.count(s[windowEnd])){
                while(s[windowStart] != s[windowEnd]){
                    charset.erase(s[windowStart]);
                    windowStart++;
                }
                windowStart++;
            }
            else{
                charset.insert(s[windowEnd]);
                strlength = (windowEnd - windowStart + 1 > strlength) ? (windowEnd - windowStart + 1) : strlength;
            }
        }
        return strlength;
    }
int lengthOfLongestSubstringV2(string s) {//faster
    int n = s.length();
    set<char> st;
    int maxLen = 0, windowStart = 0, windowEnd = 0;

    while(windowEnd < n) {
      if(st.count(s[windowEnd]) == 0) {
        st.insert(s[windowEnd]);
        maxLen = max(maxLen, windowEnd-windowStart+1);
        windowEnd++;
      }
      else {
        st.erase(st.find(s[windowStart]));
        windowStart++;
      }
    }

    return maxLen;
}
int main(){
	string s;
	cin >> s;
	cout << lengthOfLongestSubstringV2(s) << endl;
} 
