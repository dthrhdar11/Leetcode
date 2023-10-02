//Divide and Conquer
//LCP(1...N) = LCP(LCP(1...K),LCP(K+1...N))
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string commonPrefix(string left,string right){
	int mn = min(left.length(),right.length());
	for(int i=0;i<mn;++i){
		if(left[i] != right[i])
			return left.substr(0,i);
	}
	return left.substr(0,mn);
}
string DivideAndConquer(vector<string>& strs, int l,int r){
	if(l == r){
		return strs[l];
	}
	else{
		int mid = (l + r) / 2;
		string LCPleft = DivideAndConquer(strs,l,mid);
		string LCPright = DivideAndConquer(strs,mid+1,r);
		return commonPrefix(LCPleft,LCPright);
	}
}
string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0)
    	return "";
    return DivideAndConquer(strs,0,strs.size()-1);
}
int main(){
	vector<string> v{"fl","fl","fl"};
	cout << longestCommonPrefix(v) << endl;
}
