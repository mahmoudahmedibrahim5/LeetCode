#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int a = 0, b = nums.size() - 1;
        vector<pair<int,int>>arr(b + 1);
        for(int i = 0; i < b + 1; i++){
            arr[i].first = nums[i];
            arr[i].second = i;
        }
        sort(arr.begin(), arr.end());

        vector<int> ans;
        while(a < b)
        {
            if(arr[a].first + arr[b].first > target)
                b--;
            else if(arr[a].first + arr[b].first < target)
                a++;
            else
                break;
        }
        ans.push_back(arr[a].second);
        ans.push_back(arr[b].second);
        return ans;
    }
};
