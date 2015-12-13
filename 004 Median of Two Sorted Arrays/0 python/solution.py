#!/usr/bin/env python
import random
from random import randrange

class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        len1, len2 = len(nums1), len(nums2)
        if len1 > len2:
            nums1, nums2 = nums2, nums1
            len1, len2 = len2, len1
        imin, imax = 0, len1
        while imin <= imax:
            i = int((imin + imax) / 2)
            j = (len1 + len2 + 1) / 2 - i
            print("i = " + repr(i) + ", j = " + repr(j))
            if j > 0 and i < len1 and nums2[j - 1] > nums1[i]:
                imin = i + 1
            elif i > 0 and j < len2 and nums1[i - 1] > nums2[j]:
                imax = i - 1
            else:
                if i == 0:
                    num1 = nums2[j - 1]
                elif j == 0:
                    num1 = nums1[i - 1]
                else:
                    num1 = max(nums1[i - 1], nums2[j - 1])

                if (len1 + len2) % 2 != 0:
                    return float(num1)

                if i == len1:
                    num2 = nums2[j]
                elif j == len2:
                    num2 = nums1[i]
                else:
                    num2 = min(nums1[i], nums2[j])

                return (num1 + num2) / 2.0

if __name__ == '__main__':
    sol = Solution()
    random.seed()
    nums1 = range(randrange(10), randrange(10, 20))
    nums2 = range(randrange(10), randrange(10, 20))
    nums = sorted(nums1 + nums2)
    print(repr(nums1))
    print(repr(nums2))
    print(repr(nums))
    print(sol.findMedianSortedArrays(nums1, nums2))
