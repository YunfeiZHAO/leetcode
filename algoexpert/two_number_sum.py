def twoNumberSum(array, targetSum):
    array_dict = {}
    for i, e in enumerate(array):
        complement = targetSum - e
        if complement in array_dict:
            return [i, array_dict[complement]]
        array_dict[e] = i

def twoNumberSum2(array, targetsum):
    l = len(array)
    for i in range(l-1):
        for j in range(i+1, l):
            if(array[i] + array[j] == targetsum):
                return [i,j]

if __name__ == "__main__":
    a = [3,5,-4,8,11,1,-1,6]
    t = 10
    # print(twoNumberSum(a, t))
    print(twoNumberSum2(a,t))