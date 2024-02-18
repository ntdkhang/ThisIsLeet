# https://leetcode.com/problems/longest-happy-string/

"""
string contains only 'a', 'b', and 'c'
does not contain "aaa", "bbb", or "ccc" as a substring
contains at most a occurence of the letter 'a'
contains at most b occurence of the letter 'b'
contains at most c occurence of the letter 'c'

given 3 integers a, b, and c, returns the longest possible happy string
""" 


class Solution(object):
    def getLongestLenAndIndex(self, letterList):
        longestLen = 0
        longestIndex = 0
        for index, letterString in enumerate(letterList):
            if longestLen < len(letterString):
                longestLen = len(letterString)
                longestIndex = index
        return longestLen, longestIndex

    def sortBaseOnLength(self, str):
        return len(str)

    def longestDiverseString(self, a, b, c):
        """
        :type a: int
        :type b: int
        :type c: int
        :rtype: str
        """

        #Brainstorming  

        """
        a = 1
        b = 1
        c = 2
        """

        "aabaabaabaaccba"

        letterList = ['a' * a, 'b' * b, 'c' * c]
        # ['aaaaaa', 'bbb', 'c']

        happyString = ""
        last2Letter = "x"
        while True:
            letterList.sort(reverse=True, key=self.sortBaseOnLength)
            if len(letterList[0]) == 0:
                return happyString
            letterPicked = letterList[0][0]
            if last2Letter == letterPicked * 2:
                if len(letterList[1]) == 0:
                    return happyString
                letterPicked = letterList[1][0] # Pick the second longest letter remaining
                letterList[1] = letterList[1][1:] # remove one letter from the string
            else:
                letterList[0] = letterList[0][1:]

            happyString = happyString + letterPicked
            last2Letter = last2Letter[-1] + letterPicked
