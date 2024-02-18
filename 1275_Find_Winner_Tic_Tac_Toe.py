# https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/

class Solution(object):
    def tictactoe(self, moves):
        """
        :type moves: List[List[int]]
        :rtype: str
        """

        # construct the table
        grid = []
        for row in range(3):
            grid.append([''] * 3)

        player = 0
        for move in moves:
            letter = 'X' if player == 0 else 'O'
            grid[move[0]][move[1]] = letter 
            player = (player + 1) % 2

        winner = 'N' # None, 'X' = 'A', 'O' = 'B'

        # Check horizontal winner 
        for row in range(3):
            if grid[row][0] == grid[row][1] and grid[row][1] == grid[row][2]:
                winner = grid[row][0]

        #Check vertical winner
        for col in range(3):
            if grid[0][col] == grid[1][col] and grid[1][col] == grid[2][col]:
                winner = grid[0][col]

        # Check diagonal winner 
        if grid[0][0] == grid[1][1] and grid[1][1] == grid[2][2]:
            winner = grid[0][0]
        
        if grid[2][0] == grid[1][1] and grid[1][1] == grid[0][2]:
            winner = grid[1][1]

        if winner == 'X':
            return 'A'
        elif winner == 'O':
            return 'B'
        elif len(moves) == 9:
            return 'Draw'
        else:
            return 'Pending'
