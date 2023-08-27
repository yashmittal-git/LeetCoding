class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        itr1 = m-1
        itr2 = n-1
        writeItr = m+n-1

        while itr2>=0:
            if itr1>=0 and nums1[itr1] > nums2[itr2]:
                nums1[writeItr] = nums1[itr1]
                itr1-=1
            else:
                nums1[writeItr] = nums2[itr2]
                itr2-=1
            writeItr-=1