//Find the Longest palindromic substring in a string
//ex: babad => bab, acd => a
//palidromic = ¦^¤å 
//Dynamic Programming Approach
#include<iostream>
#include<string>
using namespace std;
string longestPalindrome(string s) {
        if(s == "")
            return s;
        int strlen = s.length();
        string ans;
        int maxlen = 0;
        
        bool dp[strlen][strlen];
        
        for(int j=0;j<strlen;++j){
            for(int i=0;i<=j;++i){
                bool judge = (s[i]==s[j]);
                
                dp[i][j] = (j-i>2) ? (dp[i+1][j-1]&&judge) : (judge);
                
                if(dp[i][j] && j-i+1 > maxlen){
                    maxlen = j - i + 1;
                    ans = s.substr(i,maxlen);
                }
            }
        }
        return ans; 
    }
int main(){
	string s;
	cin >> s;
	cout << longestPalindrome(s) << endl;
}
