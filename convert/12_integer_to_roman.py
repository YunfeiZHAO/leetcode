def intToRoman(num: int) -> str:
    dict = {1000: 'M', 900: 'CM', 500: 'D', 400: 'CD', 100: 'C', 90: 'XC', 50: 'L', 40: 'XL', 10: 'X', 9: 'IX', 5: 'V', 4: 'IV', 1: 'I'} 
    result = ''
    for k, v in dict.items():
        n = num // k
        num %= k
        result += v * n
    return result




if __name__ == "__main__":
    num = 1994
    # print(twoNumberSum(a, t))
    print(intToRoman(num))