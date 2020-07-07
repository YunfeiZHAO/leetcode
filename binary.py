from typing import List

def hammingDistance(x: int, y: int) -> int:
    '''
    The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
    '''

    def DtoB(x: int) -> List[int]:
        L = [0] * 31
        i = 0
        while x != 0:
            L[30 - i] = x % 2
            x = x // 2
            i += 1
        return L

    x_b = DtoB(x)
    y_b = DtoB(y)
    dist = 0
    for xb, yb in zip(x_b, y_b):
        if xb != yb:
            dist += 1
    return dist


def hammingDistance2(x: int, y: int) -> int:
    return bin(x^y).count("1")


def hammingDistance3(self, x: int, y: int) -> int:
    numDifferences = 0
    while(x > 0 or y > 0):
        if (x & 0x01) != (y & 0x01):
            numDifferences += 1
        x >>= 1
        y >>= 1
    return numDifferences

if __name__ == "__main__":
    print(hammingDistance(2, 0))