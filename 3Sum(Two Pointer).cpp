//given an integer array, find three numbers(must be diffrent index,can be same number)
//that its sum = 0
//Two Pointer
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector< vector<int> > ans;
        for(int i=0;i<nums.size()-2;++i){
            if(nums[i] > 0)
                break;
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int Start = i+1,End = nums.size()-1;
            int target = nums[i] * -1;
            while(Start < End){
                if(nums[Start] + nums[End] > target){
                    End--;
                }
                else if(nums[Start] + nums[End] == target){
                    vector<int> v(3);
                    v[0] = nums[i];
                    v[1] = nums[Start];
                    v[2] = nums[End];
                    ans.push_back(v);
                    while(Start < End && nums[Start] == nums[Start+1]) Start++;
                    while(Start < End && nums[End] == nums[End-1]) End--;
                    Start++;
                    End--;
                }
                else{
                    Start++;
                }
            }
        }
        return ans;
    }
int main(){
	vector<int> v{-1,0,1,2,-1,-4};
	auto ans = threeSum(v);
	for(int i=0;i<ans.size();++i){
		cout << "[ ";
		for(int &p:ans[i]){
			cout << p << " ";
		}
		cout << "]" << endl;
	}
}
