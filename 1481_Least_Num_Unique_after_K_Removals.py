from typing import List

# class Solution(object):
#     def findLeastNumOfUniqueInts(self, arr, k):
#         """
#         :type arr: List[int]
#         :type k: int
#         :rtype: int
#         """
#         appearance = {}
#
#         for num in arr:
#             if num in appearance:
#                 appearance[num] += 1
#             else:
#                 appearance[num] = 1
#         # count = k
#
#         sortedDict = dict(sorted(appearance.items(), key= lambda x:x[1]))
#
#         numRemain = len(sortedDict)
#         for count in list(sortedDict.values()):
#             k -= count   
#             if k >= 0:
#                 numRemain -= 1
#             if k <= 0:
#                 return numRemain
#
#         return numRemain
#
#








































class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        numCount = {}
        for num in arr:
            if num in numCount:
                numCount[num] += 1
            else:
                numCount[num] = 1
        sortedDict = {key : val for key, val in sorted(numCount.items(), key=lambda item: item[1]) }

        numRemain = len(sortedDict)

        for _, count in enumerate(sortedDict):
            k -= count
            numRemain -= 1
            if k == 0:
                return numRemain 
            if k < 0:
                return numRemain + 1
        return numRemain









































