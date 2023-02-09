def isValidSubsequence(array, sequence):
    idx = 0
    for e in array:
        if idx >= len(sequence):
            return True
        if e == sequence[idx]:
            idx += 1
    return idx == len(sequence)



if __name__ == "__main__":
    array = [5,1,22,25,6,-1,8, 10]
    sequence = [1,6,-1,10]
    print(isValidSubsequence(array, sequence))
