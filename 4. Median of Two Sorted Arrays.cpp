#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        int n = (int)nums1.size();
        int m = (int)nums2.size();

        int c1 = 0, c2 = 0;
        for(int i = 0; i < n + m; i++)
        {
            if(c2 == m){
                while(c1 != n)
                    arr.push_back(nums1[c1++]);
                break;
            }
            if(c1 == n){
                while(c2 != m)
                    arr.push_back(nums2[c2++]);
                break;
            }
            if(nums1[c1] < nums2[c2])
            {
                arr.push_back(nums1[c1]);
                c1++;
            }
            else
            {
                arr.push_back(nums2[c2]);
                c2++;
            }
        }

        if((n + m) % 2 == 0){
            return ((double)arr[((n + m) / 2) - 1] + (double)arr[(n + m) / 2]) / 2;
        }
        else{
            return (double)arr[(n + m) / 2];
        }
    }
};