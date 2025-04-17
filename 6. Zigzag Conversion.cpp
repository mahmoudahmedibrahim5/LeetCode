#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        string result;
        int x = 2 * (numRows - 1);
        for(int i = 0; i < numRows; i++)
        {
            for(int j = i; j < (int)s.size(); j+= x)
            {
                result.push_back(s[j]);
                if(i != 0 && i != (numRows - 1) && (j + (x - 2 * i)) < (int)s.size())
                    result.push_back(s[j + (x - 2 * i)]);
            }
        }
        return result;
    }
};
