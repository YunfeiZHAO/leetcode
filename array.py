from typing import List
#
## array problems
#

def prisonAfterNDays(cells: List[int], N: int) -> List[int]:
    '''
    the array repeat every 14 times
    :param cells: [1, 1, 1, 1, 1, 0, 0, 1]
    :param N: number
    :return: new array
    '''
    N = N % 14
    if not N:
        N = 14
    for _ in range(N):
        cells = [0] + [cells[i - 1] ^ cells[i + 1] ^ 1 for i in range(1, 7)] + [0]
    return cells



if __name__ == "__main__":
    pass