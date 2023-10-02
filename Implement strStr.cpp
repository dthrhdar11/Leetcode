#include<iostream>
#include<string>
using namespace std;
int strStr(string haystack, string needle) {
        if(needle.length() == 0)
            return 0;
        if(haystack.length() < needle.length())
            return -1;
        for(int i=0;i<=haystack.length()-needle.length();++i){
            if(haystack.substr(i,needle.length()) == needle)
                return i;
        }
        return -1;
    }
int main(){
	cout << strStr("hello","ll") << endl;
	cout << strStr("aaaaa","bba") << endl;
}
