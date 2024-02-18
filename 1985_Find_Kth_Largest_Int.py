from typing import List

class Solution:
    def kthLargestNumber(self, nums: List[str], k: int) -> str:
        nums = sorted(nums, reverse=True, key= lambda x: int(x))
        return nums[k - 1]
    def something(self):
        self
