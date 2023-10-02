//Divide And Conquer
#include<iostream>
#include<vector>
using namespace std;
string digitToLetter(int x){
        if(x == 2)
            return "abc";
        else if(x == 3)
            return "def";
        else if(x == 4)
            return "ghi";
        else if(x == 5)
            return "jkl";
        else if(x == 6)
            return "mno";
        else if(x == 7)
            return "pqrs";
        else if(x == 8)
            return "tuv";
        else 
            return "wxyz";
}
void getCombination(string digits,vector<string>& ans,string nowword){
        if(digits.length() == 0){
            ans.push_back(nowword);
            return;
        }
        string s = digitToLetter(digits[0] - '0');
        digits = digits.substr(1,digits.length()-1);
        for(int i=0;i<s.length();++i){
            getCombination(digits,ans,nowword+s.substr(i,1));
        }
    }
vector<string> letterCombinations(string digits) {
		vector<string> ans;
        if(digits.length() == 0)
            return ans;
        getCombination(digits,ans,"");
        return ans;
    }
    
    
int main(){
	string digits = "234";
	vector<string> v = letterCombinations(digits);
	for(string &p:v){
		cout << p << " ";
	} 
} 
