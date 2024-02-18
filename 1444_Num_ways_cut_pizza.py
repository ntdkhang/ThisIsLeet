from typing import List
class Solution:
    appleCount = []
    waysToCut = []
    totalRow = 0
    totalCol = 0
    MOD = 1000000007

    def ways(self, pizza: List[str], pieces: int) -> int:
        self.totalCol = len(pizza[0])
        self.totalRow = len(pizza)
        def countApple():
            self.appleCount = [[0 for i in range(self.totalCol + 1)] for j in range(self.totalRow + 1)]
            for row in range(len(pizza) - 1, -1, -1):
                for column in range(len(pizza[0]) - 1, -1, -1):
                    toAdd = 1 if pizza[row][column] == 'A' else 0
                    previousApple = self.appleCount[row + 1][column] + self.appleCount[row][column + 1] - self.appleCount[row + 1][column + 1]
                    self.appleCount[row][column] += previousApple + toAdd

        countApple()

        if pieces == 1:
            return 1 if self.appleCount[0][0] > 0 else 0
        waysToCut = [[[-1 for i in range(pieces)] for j in range(self.totalCol)] for k in range(self.totalRow)]


        def countWaysToCut(row: int, col: int, cuts: int) -> int:
            # repeated case 
            if waysToCut[row][col][cuts] != -1:
                return waysToCut[row][col][cuts]  

            # base case
            if cuts == 0:
                if self.appleCount[row][col] > 0:
                    waysToCut[row][col][cuts] = 1
                else:
                    waysToCut[row][col][cuts] = 0
                return waysToCut[row][col][cuts] 
            
            waysToCut[row][col][cuts] = 0

            # horizontal cut 
            for rowToCut in range(row + 1, self.totalRow):
                if self.appleCount[row][col] - self.appleCount[rowToCut][col] > 0:
                    waysToCut[row][col][cuts] = (waysToCut[row][col][cuts] + countWaysToCut(rowToCut, col, cuts - 1)) % self.MOD
                

            # vertical cut
            for colToCut in range(col + 1, self.totalCol):
                if self.appleCount[row][col] - self.appleCount[row][colToCut] > 0:
                    waysToCut[row][col][cuts] = (waysToCut[row][col][cuts] + countWaysToCut(row, colToCut, cuts - 1)) % self.MOD

            return waysToCut[row][col][cuts]
            

        return countWaysToCut(0, 0, pieces - 1)
        return waysToCut[0][0][pieces - 1]
        print(self.appleCount)
        return 0       


