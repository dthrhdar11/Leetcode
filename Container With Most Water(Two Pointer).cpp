//Two Pointer Approach
//let two pointers at start/end of vector
//smaller side decide water area
//go inward if one side is smaller
#include<iostream>
#include<vector>
using namespace std;
int maxArea(vector<int>& height){
        int start = 0 ,end = height.size() - 1;
        int maxArea = 0;
        while(start != end){
            int lowh = min(height[start],height[end]);
            int nowArea = lowh * (end-start);
            if(nowArea > maxArea){
                maxArea = nowArea;
            }
            if(height[start] < height[end]){
                start++;
            }
            else{
                end--;
            }
        }
        return maxArea;
}
int main(){
	vector<int> v{1,8,6,2,5,4,8,3,7};
	cout << maxArea(v);
} 
