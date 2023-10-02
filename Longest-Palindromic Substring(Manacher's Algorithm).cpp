#include<iostream>
#include<string>
using namespace std;
string longestPalindrome(string s) {
        int N = s.length();
        if(N == 0)
            return "";
        else if(N == 1)
        	return s;
        N = 2*N + 1;
        int L[N];//LPS length Array
        L[0] = 0;
        L[1] = 1;
        int CenterPosition = 1;
        int CenterRightPosition = 2;
        int i = 0;//CurrentRightPosition
        int CurrentLeftPosition;
        int expand = -1;
        int diff = -1;
        int maxLPSlen = 0;
        int maxLPSCenterPosition = 0;
        int start = -1;
        int end = -1;
        
        for(i = 2 ; i < N ; i++){
            //get currentLeftPosition for currentRightPosition i
            CurrentLeftPosition = 2 * CenterPosition - i;
            //Reset expand - means no expansion required
            expand = 0;
            diff = CenterRightPosition - i;
            if(diff >= 0){
                if(L[CurrentLeftPosition] < diff) //Case 1
                    L[i] = L[CurrentLeftPosition];
                else if(L[CurrentLeftPosition] == diff && CenterRightPosition == N-1)//Case 2
                    L[i] = L[CurrentLeftPosition];
                else if(L[CurrentLeftPosition] == diff && CenterRightPosition < N-1)//Case 3
                {
                    L[i] = L[CurrentLeftPosition];
                    expand = 1;//expansion required
                }
                else if(L[CurrentLeftPosition] > diff)//Case 4
                {
                    L[i] = diff;
                    expand = 1;//expansion required
                }
            }
            else{
                L[i] = 0;
                expand = 1;//expansion required
            }
            if(expand == 1){
            //Attempt to expand palindrome centered at currentRightPosition i
            //Here for odd positions, we compare characters and
            //if match then increment LPS Length by ONE
            //If even position, we just increment LPS by ONE without
            //any character comparison
            while (((i + L[i]) < N && (i - L[i]) > 0) &&
                ( ((i + L[i] + 1) % 2 == 0) || (s[(i + L[i] + 1)/2] == s[(i-L[i]-1)/2] )))
            {
                L[i]++;
            }
            }
            
            if(L[i] > maxLPSlen){
                maxLPSlen = L[i];
                maxLPSCenterPosition = i;
            }
        // If palindrome centered at currentRightPosition i
        // expand beyond centerRightPosition,
        // adjust centerPosition based on expanded palindrome.
        if (i + L[i] > CenterRightPosition)
        {
            CenterPosition = i;
            CenterRightPosition = i + L[i];
        }
        }
        start = (maxLPSCenterPosition - maxLPSlen) / 2;
        return s.substr(start,maxLPSlen);
}
int main(){
	string s;
	cin >> s;
	cout << longestPalindrome(s);
}
