#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int findUpMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 > len2) return findUpMedianSortedArrays(nums2, nums1);
        if (len1 == 0) return nums2[len2 / 2];
        if (len1 == 1) {
            if (len2 == 1) return nums1[0] < nums2[0] ? nums2[0] : nums1[0];
            if (len2 % 2 == 0) {
                if (nums1[0] >= nums2[len2 / 2]) return nums2[len2 / 2];
                else if (nums1[0] <= nums2[len2 / 2 - 1]) return nums2[len2 / 2 - 1];
                else return nums1[0];
            }
            else {
                if (nums1[0] >= nums2[len2 / 2 + 1]) return nums2[len2 / 2 + 1];
                else if (nums1[0] <= nums2[len2 / 2 - 1]) return nums2[len2 / 2];
                else return nums1[0] < nums2[len2 / 2] ? nums2[len2 / 2] : nums1[0] ;
            }
        }

        double m1, m2;
        m1 = nums1[len1 / 2];
        m2 = nums2[len2 / 2];
        
        if (m1 == m2) return m1;
        else if (m1 < m2) {
            nums1.erase(nums1.begin(), nums1.begin() + (len1 / 2));
            nums2.erase(nums2.end() - (len1 / 2), nums2.end());
            return findUpMedianSortedArrays(nums1, nums2);
        }
        else {
            nums2.erase(nums2.begin(), nums2.begin() + (len1 / 2));
            nums1.erase(nums1.end() - (len1 / 2), nums1.end());
            return findUpMedianSortedArrays(nums1, nums2);
        }
        return 0; // never reach here!
    }

    int findDownMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 > len2) return findDownMedianSortedArrays(nums2, nums1);
        if (len1 == 0)  return nums2[(len2 - 1) / 2];
        if (len1 == 1) {
            if (len2 == 1) return nums1[0] < nums2[0] ? nums1[0] : nums2[0];
            if (len2 % 2 == 0) {
                if (nums1[0] >= nums2[len2 / 2]) return nums2[len2 / 2];
                else if (nums1[0] <= nums2[len2 / 2 - 1]) return nums2[len2 / 2 - 1];
                else return nums1[0];
            }
            else {
                if (nums1[0] >= nums2[len2 / 2 + 1]) return nums2[len2 / 2];
                else if (nums1[0] <= nums2[len2 / 2 - 1]) return nums2[len2 / 2 - 1];
                else return nums1[0] > nums2[len2 / 2] ? nums2[len2 / 2] : nums1[0] ;
            }
        }

        double m1, m2;
        m1 = nums1[(len1 - 1) / 2];
        m2 = nums2[(len2 - 1) / 2];
        
        if (m1 == m2) return m1;
        else if (m1 < m2) {
            nums1.erase(nums1.begin(), nums1.begin() + (len1 / 2));
            nums2.erase(nums2.end() - (len1 / 2), nums2.end());
            return findDownMedianSortedArrays(nums1, nums2);
        }
        else {
            nums2.erase(nums2.begin(), nums2.begin() + (len1 / 2));
            nums1.erase(nums1.end() - (len1 / 2), nums1.end());
            return findDownMedianSortedArrays(nums1, nums2);
        }
        return 0; // never reach here!
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> n1(nums1), n2(nums2);
        int upmid = findUpMedianSortedArrays(nums1, nums2);
        int downmid = findDownMedianSortedArrays(n1, n2);
        //printf("up: %d, down: %d\n", upmid, downmid);
        return (upmid + downmid) / 2.0;
    }
};

int main() {
    int a[] = {1, 3};
    int b[] = {2, 4};
    vector<int> n1(a, a+2);
    vector<int> n2(b, b+2);
    Solution s;
    double ret = s.findMedianSortedArrays(n1, n2);
    printf("%.3lf\n", ret); 
    return 0;
}