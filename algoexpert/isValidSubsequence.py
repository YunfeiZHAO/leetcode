def sortedSquareArray(array):
    if array[0] >= 0: # all elements are positive
        return [e**2 for e in array]
    if array[-1]<= 0: # all elements are negative
        return [array[i]**2 for i in range(len(array)-1, -1, -1)]
    for k, e in enumerate(array):
        if e >= 0:
            break
    neg_array = [array[i]**2 for i in range(k-1, -1, -1)] # reverse negative part
    pos_array = [e**2 for e in array[k:]]


    # merge two sorted array
    i = j = 0
    result = []
    while(i<len(neg_array) and j<len(pos_array)):
        if neg_array[i] <= pos_array[j]:
            result.append(neg_array[i])
            i += 1
        else:
            result.append(pos_array[j])
            j += 1

    if i < len(neg_array):
        result = result + neg_array[i:]
    if j < len(pos_array):
        result = result + pos_array[j:]
    return result

    

if __name__ == "__main__":
    array = [-3,-2, 0,1,2,3]
    print(sortedSquareArray(array))


