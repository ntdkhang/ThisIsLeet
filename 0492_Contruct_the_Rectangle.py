# https://leetcode.com/problems/construct-the-rectangle/


"""
W * L == area
W <= L 
L - W is minimized
"""

import math
class Solution(object):
    def constructRectangle(self, area):
        """
        :type area: int
        :rtype: List[int]
        """
        end = int(round(math.sqrt(area)))
        for w in range(end, 0, -1):
            l = area // w
            if l*w == area:
                return [l, w]

