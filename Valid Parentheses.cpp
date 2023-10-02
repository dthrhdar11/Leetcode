//stack
#include<iostream>
#include<map>
#include<stack>
using namespace std;
bool isValid(string s) {
        map<char,char> mp;
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';
        if(s.length() % 2 == 1)
            return false;
        stack<char> stk;
        for(int i=0;i<s.length();++i){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stk.push(s[i]);
            }
            else{
                if(stk.empty())
                    return false;
                else if(mp[stk.top()] != s[i])
                    return false;
                else{
                    stk.pop();
                }
            }
        }
        if(stk.empty())
            return true;
        else
            return false;
}
int main(){
	cout << "({})([]) is " << isValid("({})([])") << endl;
	cout << "({})([)] is " << isValid("({})([)]") << endl;
} 
