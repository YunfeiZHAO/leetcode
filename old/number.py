from typing import List


def nthUglyNumber(n: int) -> int:
    '''
    Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
    1 is an ugly number too
    '''
    numbers = [0] * n
    numbers[0] = 1
    point_2 = 0
    point_3 = 0
    point_5 = 0
    i = 1
    min_2 = numbers[point_2] * 2
    min_3 = numbers[point_3] * 3
    min_5 = numbers[point_5] * 5
    while i < n:
        next_number = min(min_2, min_3, min_5)
        numbers[i] = next_number
        if next_number == min_2:
            point_2 += 1
            min_2 = numbers[point_2] * 2
        if next_number == min_3:
            point_3 += 1
            min_3 = numbers[point_3] * 3
        if next_number == min_5:
            point_5 += 1
            min_5 = numbers[point_5] * 5
        i += 1
    return numbers[-1]


def nthUglyNumber2(n: int) -> int:
    ugly = sorted(2**a * 3**b * 5**c for a in range(32) for b in range(20) for c in range(14))

    def nthUglyNumber(self, n):
        return self.ugly[n-1]


def plusOne(digits: List[int]) -> List[int]:
    n = len(digits)
    for i in  range(n - 1, -1, -1):
        if digits[i] + 1 <= 9:
            digits[i] += 1
            return digits
        else:
            digits[i] = 0
            if i == 0:
                return [1] + digits



if __name__ == "__main__":
    print(plusOne([9,9]))
    pass