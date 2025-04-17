#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        bool dp[1000][1000];
        int len = (int)s.size();
        
        int start = 0, end = 0;
        for(int i = 0; i < len; i++)
            dp[i][i] = true;
        
        for(int i = 0; i < len - 1; i++)
        {
            if(s[i] == s[i + 1]){
                dp[i][i + 1] = true;
                start = i;
                end = i + 1;
            }
            else
                dp[i][i + 1] = false;
        }

        for(int i = 2; i <= len; i++)
        {
            for(int j = 0; j < len - i; j++)
            {
                if(s[j] == s[j + i] && dp[j + 1][j + i - 1]){
                    dp[j][j + i] = true;
                    start = j;
                    end = j + i;
                }else
                    dp[j][j + i] = false;
            }
        }

        return s.substr(start, end - start + 1);
    }
};