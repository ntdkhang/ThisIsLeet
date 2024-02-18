from typing import List
class Solution:

    def permute(self, nums: List[int]) -> List[List[int]]:
        def dfs(nums: List[int], path: List[int], result: List[List[int]]):
            if not nums:
                result.append(path)
            else:
                for i in range(len(nums)):
                    dfs(nums[:i] + nums[i+1:], [nums[i]] + path, result)

        result = [[]]
        dfs(nums, [], result)

        return result


