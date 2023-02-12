from typing import *

def dfs(parentheses, n_left, n_right):
    if n_left==0 and n_right==0:
        result.add(parentheses)
        return
    elif n_left == n_right:
        parentheses += '('
        dfs(parentheses, n_left-1, n_right)
    elif n_left == 0:
        parentheses += ')'
        dfs(parentheses, n_left, n_right-1)
    elif n_left < n_right:
        dfs(parentheses + '(', n_left-1, n_right)
        dfs(parentheses + ')', n_left, n_right-1)


def generateParenthesis(n: int) -> List[str]:
    global result 
    result = set()
    dfs('', n,n)
    return list(result)


def generateParenthesis1(self, n: int) -> List[str]:

    def dfs(left, right, s):
        if len(s) == n * 2:
            res.append(s)
            return 

        if left < n:
            dfs(left + 1, right, s + '(')

        if right < left:
            dfs(left, right + 1, s + ')')

    res = []
    dfs(0, 0, '')
    return res


if __name__ == '__main__':
    print(generateParenthesis(4))