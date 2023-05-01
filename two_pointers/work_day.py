def work_day(D, X):
    # Implement your solution here
    day = 0
    left_p = 0
    right_p = 0
    n = len(D)
    if n == 0:
        return 0
    while left_p < n:
        max_level = D[left_p]
        min_level = D[left_p]
        max_gap = max_level - min_level
        while  right_p < n:
            min_level = min(D[right_p], min_level)
            max_level = max(D[right_p], max_level)
            max_gap = max_level - min_level
            if right_p >= n or max_gap > X:
                break
            right_p += 1

        day += 1
        left_p = right_p
    return day


if __name__ == '__main__':
    #A = [1, 3, 6, 4, 1, 2]
    # D = [5,8,2,7]
    D = [1, 3, 6, 4, 1, 2, 100]

    X = 5
    print(work_day(D, X))

