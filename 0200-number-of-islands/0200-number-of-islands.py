class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        
        rowNumber = len(grid)
        columnNumber = len(grid[0])
        
        visited = set()
        islandCounter = 0
        
        def bfs(row ,column):
            myQueue = []
            visited.add((row, column))
            myQueue.append((row, column))
            
            while len(myQueue) != 0:
                row, column = myQueue.pop(0)
                myDirections = [[1, 0], [-1, 0], [0, 1], [0, -1]]
                
                for rowDirection, columnDirection in myDirections:
                    newrow = row + rowDirection
                    newcolumn = column + columnDirection
                    
                    if (newrow in range(rowNumber) and
                        newcolumn in range(columnNumber) and
                        grid[newrow][newcolumn] == "1" and
                        (newrow, newcolumn) not in visited):
                        
                        myQueue.append((newrow, newcolumn))
                        visited.add((newrow, newcolumn))
        
        for row in range(rowNumber):
            for column in range(columnNumber):
                if grid[row][column] == "1" and (row, column) not in visited:
                    bfs(row, column)
                    islandCounter += 1
        
        return islandCounter
                    