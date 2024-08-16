class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rowVisited=[set() for _ in range(9)]
        colVisited=[set() for _ in range(9)]
        boxVisited=[set() for _ in range(9)]
        for i in range(9):
            for j in range(9):
                if board[i][j]!='.':
                    digit=int(board[i][j])-1
                    if digit in rowVisited[i]:
                        return False
                    rowVisited[i].add(digit)
                    if digit in colVisited[j]:
                        return False
                    colVisited[j].add(digit)
                    boxId=(i//3)*3+(j//3)
                    if digit in boxVisited[boxId]:
                        return False
                    boxVisited[boxId].add(digit)
        
        return True

        