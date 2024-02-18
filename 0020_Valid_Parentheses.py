class Solution:
    def isValid(self, s: str) -> bool: 
        stack = ['N']
        map = {'N': 'N', '{': '}', '(': ')', '[': ']'}
        for char in s:
            if char in map: # open paren
                stack.append(char)
            elif map[stack.pop()] != char:
                return False

        return stack == ['N']
