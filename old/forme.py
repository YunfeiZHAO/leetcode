from typing import List

def islandPerimeter(grid: List[List[int]]) -> int:
    '''
    only one island(1s) surrounded by water(0s) get island perimeter
    '''
    l = len(grid)
    c = len(grid[0])
    perimeter = 0
    for i in range(l):
        for j in range(c):
            if grid[i][j] == 1:
                if j == 0 or grid[i][j - 1] == 0:
                    perimeter += 1
                if i == 0 or grid[i - 1][j] == 0:
                    perimeter += 1
                if j == c - 1 or grid[i][j + 1] == 0:
                    perimeter += 1
                if i == l - 1 or grid[i + 1][j] == 0:
                    perimeter += 1
    return perimeter

def islandPerimeter2(grid: List[List[int]]) -> int:
    rows = len(grid)
    cols = len(grid[0])
    result = 0
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 1:
                result += 4
                if r > 0 and grid[r - 1][c] == 1:
                    result -= 2
                if c > 0 and grid[r][c - 1] == 1:
                    result -= 2
    return result


if __name__ == "__main__":
    a = [[1, 1, 0], [0, 1, 1], [0, 1, 0]]
    print(islandPerimeter(a))
    pass