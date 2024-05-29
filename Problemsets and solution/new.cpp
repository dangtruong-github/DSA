#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        long long dp1[size1+1], dp2[size2+2];
        int cnt1 = 0, cnt2 = 0;
        while (cnt1 < size1 || cnt2 < size2)
        {
            if (cnt1 == size1)
            {
                if (cnt2 == 0) dp2[cnt2] = nums2[cnt2];
                else dp2[cnt2] = dp2[cnt2-1] + nums2[cnt2];
                cnt2++;
                continue;
            }
            if (cnt2 == size2)
            {
                if (cnt1 == 0) dp1[cnt1] = nums1[cnt1];
                else dp1[cnt1] = dp1[cnt1-1] + nums1[cnt1];
                cnt1++;
                continue;
            }
            if (nums1[cnt1] < nums2[cnt2])
            {
                if (cnt1 == 0) dp1[cnt1] = nums1[cnt1];
                else dp1[cnt1] = dp1[cnt1-1] + nums1[cnt1];
                cnt1++;
            }
            else if (nums1[cnt1] > nums2[cnt2])
            {
                if (cnt2 == 0) dp2[cnt2] = nums2[cnt2];
                else dp2[cnt2] = dp2[cnt2-1] + nums2[cnt2];
                cnt2++;
            }
            else
            {
                if (cnt1 == 0 && cnt2 == 0)
                {
                    dp1[cnt1] = nums1[cnt1];
                    dp2[cnt2] = nums2[cnt2];
                }
                else if (cnt1 == 0)
                {
                    dp2[cnt2] = dp2[cnt2-1] + nums2[cnt2];
                    dp1[cnt1] = dp2[cnt2];
                }
                else if (cnt2 == 0)
                {
                    dp1[cnt1] = dp1[cnt1-1] + nums1[cnt1];
                    dp2[cnt2] = dp1[cnt1];
                }
                else
                {
                    dp1[cnt1] = max(dp2[cnt2-1], dp1[cnt1-1]) + nums1[cnt1];
                    dp2[cnt2] = dp1[cnt1];
                }
                cnt1++;
                cnt2++;
            }
        }
        long long ans = max(dp1[size1-1], dp2[size2-1]) % 1000000007;
        return ans;
    }
};