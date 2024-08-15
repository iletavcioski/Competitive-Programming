#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = 0;
        int r1 = nums1.size() - 1;
        int goal = (nums1.size() + nums2.size()) / 2;
        bool two = false;
        if ((nums1.size() + nums2.size()) % 2 == 0) {
            two = true;
        }
        while (l1 < r1) {
            int mid1 = (l1 + r1) / 2;
            int num1 = nums1[mid1];
            int count1 = mid1;
            int l2 = 0;
            int r2 = nums2.size() - 1;
            int bound1 = 1e9;
            if (mid1 + 1 < nums1.size()) {
                bound1 = nums1[mid1 + 1];
            }
            if (mid1 > goal) {
                r1 = mid1 - 1;
                continue;
            }
            if (mid1 + 1 + nums2.size() < goal) {
                l1 = mid1 + 1;
                continue;
            }

            while (l2 < r2) {
                int mid2 = (l2 + r2) / 2;
                int num2 = nums2[mid2];
                int count2 = mid2;
                if (num2 >= bound1) {
                    r2 = mid2 - 1;
                    continue;
                } else if (num2 < num1) {
                    l2 = mid2 + 1;
                    continue;
                } else {
                    if ((count1 + count2 + 1) == goal) {
                        if (two) {
                            if (mid2 - 1 > 0 && nums2[mid2 - 1] >= num1) {
                                return (num2 + nums2[mid2 - 1]) / 2;
                            } else { 
                                return (num2 + num1) / 2;
                            }
                        } else {
                            return num2;
                        }
                    } else if ((count1 + count2 + 1) > goal) {
                        r2 = mid2 - 1;
                    } else {
                        l2 = mid2 + 1;
                    }
                }
            }
            l1 = mid1 + 1;
        }
    }
};

int main() {
    Solution x;
    vector<int> v1 = {1, 3};
    vector<int> v2 = {2};
    cout << x.findMedianSortedArrays(v1, v2) << endl;
    return 0;
}

