#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool check(int i, int j, string& s)
    {
        while (j > i)
        {
            if(s[j] != s[i])
                return false;
            
            j--;
            i++;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int len = (int)s.size();
        for(int i = len; i > 1; i--)
        {
            for(int j = 0; j <= len - i; j++)
            {
                if(check(j, j + i - 1, s))
                    return s.substr(j, i);
            }
        }
        return s.substr(0, 1);
    }
};

int main()
{
    Solution s;
    cout << s.longestPalindrome("babad") << endl;
}
