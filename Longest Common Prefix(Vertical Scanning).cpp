//vertical scanning
#include<iostream>
#include<vector>
using namespace std;
//need a lot of check
string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.size() == 1)
            return strs[0];
        bool end = false;
        int charpos = 0;
        while(!end){
            if(charpos == strs[0].length())
                break;
            if(strs[0] == "")
                return "";
            char fix = strs[0][charpos];
            for(int i=1;i<strs.size();++i){
                if(strs[i] == "")
                    return "";
                if(strs[i].length() < charpos || strs[i][charpos] != fix){
                    end = true;
                    break;
                }
            }
            if(!end)
                ans += fix;
            
            charpos++;
        }
        return ans;
}
//better way
string longestCommonPrefixV2(vector<string>& strs){
	if(strs.size() == 0)
		return "";
	for(int i=0;i<strs[0].length();++i){
		char c = strs[0][i];
		for(int j=1;j<strs.size();++j){
			if(i == strs[j].length() || strs[j][i] != c){
				return strs[0].substr(0,i);
			}
		}
	}
	return strs[0];
}
int main(){
	vector<string> v{"flo","flo","flo"};
	cout << longestCommonPrefixV2(v) << endl;
}
