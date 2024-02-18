
class CaDoBongDa:
    currentGoals = 0
    team1Goals = 0
    team2Goals = 0

    def winBet(self, rate: float, bet: int) -> int:
        return int(bet*(rate - 1))
    
    def loseBet(self, bet: int) -> int:
        return -bet


    def taiChauA(self, goals: float, rate: float, bet: int) -> int:
        if self.currentGoals > goals:
            return self.winBet(rate, bet)
        else:
            return self.loseBet(bet)
    
    def team1x2(self, result: int, rate: float, bet: int) -> int:
        """
        winDrawLose: (0 for draw, 1 for team1, 2 for team2)
        """
        if self.team1Goals > self.team2Goals and result == 1:
            return self.winBet(rate, bet)
        elif self.team1Goals < self.team2Goals and result == 2:
            return self.winBet(rate, bet)
        elif self.team1Goals == self.team2Goals and result == 0:
            return self.winBet(rate, bet)
        else:
            return self.loseBet(bet)

    def calculateBets(self):
        self.team1Goals = 3
        self.team2Goals = 2
        self.currentGoals = self.team1Goals + self.team2Goals
        winning = -100000 + 669000 - 300000
        #winning += self.taiChauA(goals=6, rate=5.28, bet=100000)
        winning += self.team1x2(result=0, rate=4.85, bet=100000)
        winning += self.team1x2(result=1, rate=3.42, bet=100000)
        winning += self.team1x2(result=2, rate=6, bet=100000)
        winning += self.team1x2(result=2, rate=2.65, bet=200000)
        print(winning)
        
    
cado = CaDoBongDa()
cado.calculateBets()
